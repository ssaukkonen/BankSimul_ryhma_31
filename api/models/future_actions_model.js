const db = require('../database');

const future_actions = {
  getById: function(id, callback) {
    return db.query('select * from future_actions where idfuture_actions=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from future_actions', callback);
  },
  futureActions10: function(idaccount,pagenumber, callback) {
    console.log("futureActions10 model");
    return db.query('select amount,action_type,ref_num,message,recipient_number,action_date from future_actions where id_account=? order by date desc limit ?,10',[idaccount, pagenumber], callback); 
  },
  add: function(future_actions, callback) {
    return db.query(
      'insert into future_actions (id_account,amount,date,action_type,ref_num,message,recipient_number,action_date) values(?,?,?,?,?,?,?,?)',
      [future_actions.id_account, future_actions.amount, future_actions.date, future_actions.action_type, future_actions.ref_num, future_actions.message, future_actions.recipient_number, future_actions.action_date],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from future_actions where idfuture_actions=?', [id], callback);
  },
  update: function(id, future_actions, callback) {
    return db.query(
      'update future_actions set id_account=?,amount=?,date=?,action_type=?,ref_num=?,message=?,recipient_number=?,action_date=? where idfuture_actions=?',
      [future_actions.id_account, future_actions.amount, future_actions.date, future_actions.action_type, future_actions.ref_num, future_actions.message, future_actions.recipient_number, future_actions.action_date, id],
      callback
    );
  }
};
module.exports = future_actions;