const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'testiman',
  password: 'testiman',
  database: 'atm',
  timezone: "+00:00"
});
module.exports = connection;