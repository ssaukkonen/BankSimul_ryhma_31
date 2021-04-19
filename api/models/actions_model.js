const db = require('../database');

const actions = {
  getById: function(id, callback) {
    return db.query('select * from actions where id_actions=?', [id], callback);
  },
  getActions5: function(id, callback) {
    return db.query('select amount,date,action_type,ref_num,message,acc_sender from actions where id_account=? order by date desc limit 5', [id], callback);
  },
  postActions10: function(id, pagenumber, callback) {
    return db.query('select amount,date,action_type,ref_num,message,acc_sender from actions where id_account=? order by date desc limit ?,10', [id,pagenumber], callback);
  },
  getAll: function(callback) {
    return db.query('select * from actions', callback);
  },
  add: function(actions, callback) {
    return db.query(
      'insert into actions (id_account,amount,date,action_type,ref_num,message,acc_sender) values(?,?,?,?,?,?,?)',
      [actions.id_account, actions.amount, actions.date, actions.action_type, actions.ref_num, actions.message, actions.acc_sender],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from actions where id_actions=?', [id], callback);
  },
  update: function(id, actions, callback) {
    return db.query(
      'update actions set id_account=?,amount=?,date=?,action_type=?,ref_num=?,message=?,acc_sender=? where id_actions=?',
      [actions.id_account, actions.amount, actions.date, actions.action_type, actions.ref_num, actions.message, actions.acc_sender, id],
      callback
    );
  },
  balance_action: function(procedure_params, callback) {
    return db.query(
      'CALL balance_action(?,?)',
      [procedure_params.id, procedure_params.amount],
      callback
    );
  },
  money_action: function(procedure_params, callback) {
    return db.query(
      'CALL money_action(?,?,?,?,?)',
      [procedure_params.first_id, procedure_params.second_id, procedure_params.amount, procedure_params.ref_num, procedure_params.message],
      callback
    );
  }
};
module.exports = actions;