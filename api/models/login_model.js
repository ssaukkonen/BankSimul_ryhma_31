const db = require('../database');

const login={
  checkPassword: function(username, callback) {
      return db.query('SELECT id_card, pin, locked FROM card WHERE card_number = ?',[username], callback); 
    },
  updateWrongPass: function (id_card, callback) {
    console.log("updatewrongpass")
    return db.query(
      'update card set locked = locked + 1 where id_card=?',
      [id_card], callback);
  },
  updateCorrectPass: function (id_card, callback) {
    console.log("updatecorrectpass")
    return db.query(
      'update card set locked = 0 where id_card=?',
      [id_card], callback);
  }
};
          
module.exports = login;