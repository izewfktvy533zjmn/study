var express = require('express');
var router = express.Router();
var ArticleModel = require('../../models/articleModel.js');

router.post('/', function(req, res) {
    var Article = new ArticleModel();

    Article.title = req.body.title;
    Article.text = req.body.text;
    Article.setDate();

    Article.save(function(err) {
        if (err) {
            res.send(err);
        } else {
            res.json({message: "Success!"});
        }
    });
});

router.get('/', function(req, res) {
    ArticleModel.find()
        .then(function(articles) {
            res.json(articles);
        });
});

router.get('/:id', function(req, res) {
    var ArticleId = res.params.id;

    ArticleModel.findById(ArticleId, function(err, article) {
        res.json(article);
    });
})

router.delete('/:id', function(req, res) {
    var ArticleId = req.params.id;
    
    ArticleModel.deleteOne({_id: ArticleId})
        .then(function() {
            res.json({message: "Success!"});
        });
});

module.exports = router;
