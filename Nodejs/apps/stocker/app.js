#!/usr/env/bin node
const http = require('http');
const url  = require('url');
const pg   = require('pg');
const port = 3000;
const server = http.createServer(requestHandler);
const client = new pg.Client({
    user: 'ec2-user',
    host: 'localhost',
    database: 'product_inventory',
    password: 'ec2-user',
    port: 5432,
});

client.connect();
server.listen(port);
sales = 0;


function addstockHandler(query, res) {
    var queryLen = query.split('&').length - 2;
    var name   = String(query.split('&')[1].split('=')[1]);
    var amount = 1;

    if(queryLen == 1) {
        amount = Number(query.split('&')[2].split('=')[1]);

        if(amount < 0 || amount%1 != 0) {
            res.writeHead(200, {'Content-type': 'text/html'});
            res.end("ERROR\n");
            return;
        }
    }


    var q = {
        text:'insert into product(name, amount) values($1, $2)',
        values: [name, amount]
    };

    client.query(q, (err) => {
        if(err) console.log(err);
    });

    res.writeHead(200, {'Content-type': 'text/html'});
    res.end("");
}


function checkstockHandler(query, res) {
    var queryLen = query.split('&').length - 1;
    var ret;
    var ans = "";

    if(queryLen == 1) {
        var name = query.split('&')[1].split('=')[1];

        var q = {
            text:'select amount from product where name=$1',
            values: [name]
        };

        client.query(q, (err, result) => {
            if(err) console.log(err);
            else {
                if(result.rows.length > 0) ret = result.rows[0].amount;
                else ret = 0;
                ans = name +  ": " + ret + '\n';
                res.writeHead(200, {'Content-type': 'text/html'});
                res.end(ans);
            }
        });


    }
    else {
            var q = {
                text:'select name, amount from product order by name ASC'
            };
            client.query(q, (err, result) => {
                if(err) console.log(err);
                else {
                    res.writeHead(200, {'Content-type': 'text/html'});

                    for(var i=0; i<result.rows.length; i++) {
                        if(result.rows[i].amount != 0) {
                            ans = result.rows[i].name + ": " + result.rows[i].amount + '\n';
                            res.write(ans);
                        }
                    }
                    res.end("");
                }
            });
    }


}


function sellHander(query, res) {
    var queryLen = query.split('&').length - 2;
    var name = String(query.split('&')[1].split('=')[1]);
    var amount = 1;
    var price  = 0;
    var argName = "none";

    if(queryLen > 0) {
        argName = query.split('&')[2].split('=')[0];
    }

    switch(argName) {
        case 'amount':
            amount = Number(query.split('&')[2].split('=')[1]);

            if(amount < 0 || amount%1 != 0) {
                res.writeHead(200, {'Content-type': 'text/html'});
                res.end("ERROR\n");
                return;
            }

            var q1 = {
                text: 'select amount from product where name=$1',
                values: [name]
            }

            client.query(q1, (err, result, sales) => {
                if(err) console.log(err);
                else {
                    if(result.rows.length > 0) {
                        var q2 = {
                            text: 'update product set amount=$1 where name=$2',
                            values: [result.rows[0].amount - amount, name]
                        };

                        client.query(q2, (err) => {
                            if(err) console.log(err);
                        });
                    }
                }
            });

            if(queryLen == 2) {
                price = Number(query.split('&')[3].split('=')[1]);
            }
            if(price > 0) {
                sales += amount * price;
            }

            res.writeHead(200, {'Content-type': 'text/html'});
            res.end("");
            break;


        case 'price':
            price = Number(query.split('&')[2].split('=')[1]);

            if(price > 0) {
                sales += amount * price;
            }


            res.writeHead(200, {'Content-type': 'text/html'});
            res.end("");
            break;

        default:
            res.writeHead(200, {'Content-type': 'text/html'});
            res.end("");
            break

        }

}


function checksalesHandler(res) {
    res.writeHead(200, {'Content-type': 'text/html'});
    res.end("sales: " + String(sales) + '\n');
}


function deleteallHandler(res) {
    var query = {
        text:'delete from product'
    };

    client.query(query, (err, res) => {
        if(err) console.log(err);
    });

    sales = 0
    res.writeHead(200, {'Content-type': 'text/html'});
    res.end("");
}


function requestHandler(req, res) {
    var url_parts = url.parse(req.url, true);

    switch(url_parts.pathname) {
        case '/stocker':
            try {
                var query = url_parts.search.split('?')[1];
                var functionName = (query.split('&')[0]).split('=')[1];

                switch(functionName) {
                    case 'addstock':
                        addstockHandler(query, res);
                        break;

                    case 'checkstock':
                        checkstockHandler(query, res);
                        break;

                    case 'sell':
                        sellHander(query, res);
                        break;

                    case 'checksales':
                        checksalesHandler(res);
                        break;

                    case 'deleteall':
                        deleteallHandler(res);
                        break;
                }



            } catch(err) {
                    res.writeHead(200, {'Content-type': 'text/html'});
                    res.end("ERROR\n");
            }
            break;
    }

}
