#!/usr/bin/env node

const mqtt = require('mqtt');
const mqttClient = mqtt.connect('mqtt://172.29.156.95');
const pg   = require('pg');
const pgClient = new pg.Client({
    user: 'inouelab',
    host: 'localhost',
    database: 'iotomato',
    password: 'InoueLab_2018',
    port: 5432,
});

const TOPIC = 'inouelab/sensing_part/vinyl_house';
const INSERT_SQL = 'insert into vinyl_house(timestamp, air_temperature, air_humidity, air_pressure, co2_ppm, light, water_level) values($1, $2, $3, $4, $5, $6, $7)';


pgClient.connect();

mqttClient.on('connect', () => {
    console.log("connected");
});

mqttClient.subscribe(TOPIC, (err, granted) => {
    console.log(granted);
});

mqttClient.on('message', (topic, message) => {
    var data_str        = message.toString();
    var data_json       = JSON.parse(data_str);
    var timestamp       = data_json["timestamp"];
    var air_temperature = data_json["vinyl_house"]["air_temperature"];
    var air_humidity    = data_json["vinyl_house"]["air_humidity"];
    var air_pressure    = data_json["vinyl_house"]["air_pressure"];
    var co2_ppm         = data_json["vinyl_house"]["co2_ppm"];
    var light           = data_json["vinyl_house"]["light"];
    var water_level     = data_json["vinyl_house"]["water_level"];

    var query = {
        text  : INSERT_SQL,
        values: [timestamp, air_temperature, air_humidity, air_pressure, co2_ppm, light, water_level]
    };

    pgClient.query(query);

});
