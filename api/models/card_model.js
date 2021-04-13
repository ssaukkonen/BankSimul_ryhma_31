const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const card = {
  card_number: function(card_number, callback) {
    return db.query('SELECT id_account, fname, lname FROM card join customer on card.id_customer=customer.id_customer WHERE card_number = ?',[card_number], callback); 
  },
  getById: function(id, callback) {
    return db.query('select * from card where id_card=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  add: function(card, callback) {
    bcrypt.hash(card.pin, saltRounds, function(err, hash) {
    return db.query(
      'insert into card (id_customer,id_account,pin,card_number) values(?,?,?,?)',
      [card.id_customer, card.id_account, hash, card.card_number],
      callback)
    });
  },
  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },
  update: function(id, card, callback) {
    bcrypt.hash(card.pin, saltRounds, function(err, hash) {
    return db.query(
      'update card set id_customer=?,id_account=?,pin=?,card_number=? where id_card=?',
      [card.id_customer, card.id_account, hash, card.card_number, id],
      callback)
    });
  }
}
module.exports = card;