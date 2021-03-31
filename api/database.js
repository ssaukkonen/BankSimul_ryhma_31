const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'helppoheikki',
  database: 'atm'
});
module.exports = connection;