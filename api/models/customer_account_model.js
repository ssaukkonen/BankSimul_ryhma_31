const db = require('../database');

const customer_account = {
  getById: function(id, callback) {
    return db.query('select * from customer_account where id_customer_account=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from customer_account', callback);
  },
  add: function(customer_account, callback) {
    return db.query(
      'insert into customer_account (id_customer, id_account, owner) values(?,?,?)',
      [customer_account.id_customer, customer_account.id_account, customer_account.owner],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from customer_account where id_customer_account=?', [id], callback);
  },
  update: function(id, customer_account, callback) {
    return db.query(
      'update customer_account set id_customer=?, id_account=?, owner=? where id_customer_account=?',
      [customer_account.id_customer, customer_account.id_account, customer_account.owner, id],
      callback
    );
  }
};
module.exports = customer_account;