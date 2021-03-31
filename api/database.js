const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'testiman',
  password: 'testiman',
  database: 'atm'
});
module.exports = connection;