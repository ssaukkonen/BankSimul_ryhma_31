const db = require('../database');

const card = {
  getById: function(id, callback) {
    return db.query('select * from card where id_card=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  add: function(card, callback) {
    return db.query(
      'insert into card (id_customer,id_account,pin) values(?,?,?)',
      [card.id_customer, card.id_account, card.pin],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },
  update: function(id, card, callback) {
    return db.query(
      'update card set id_customer=?,id_account=?,pin=? where id_card=?',
      [card.id_customer, card.id_account, card.pin, id],
      callback
    );
  }
};
module.exports = card;