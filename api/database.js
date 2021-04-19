const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'asd',
  database: 'atm',
  timezone: "+00:00"
});
module.exports = connection;