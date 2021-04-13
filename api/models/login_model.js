const db = require('../database');

const login={
  checkPassword: function(username, callback) {
      return db.query('SELECT pin FROM card WHERE card_number = ?',[username], callback); 
    }
};
          
module.exports = login;