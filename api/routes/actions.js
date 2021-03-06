const { json } = require('express');
const express = require('express');
const router = express.Router();
const actions = require('../models/actions_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    actions.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  } else {
    actions.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

router.get('/actions5/:id?', 
function(request, response) {
  actions.getActions5(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.post('/actions10',
function(request, response) {
  actions.actions10(parseInt(request.body.idaccount),parseInt(request.body.pagenumber), function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.post('/', 
function(request, response) {
  actions.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  actions.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  actions.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.post('/balance_action', 
function(request, response) {
  actions.balance_action(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult.affectedRows);
    }
  });
});


router.post('/money_action', 
function(request, response) {
  actions.money_action(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } 
    else {
      var json=JSON.parse(JSON.stringify(dbResult[0]));
      // var tulos=JSON.parse(json[0].tulos);
      // console.log(tulos);
      //console.log(json[0].tulos);
      response.json(json[0].tulos);

      // if (tulos == 0){
      //   response.send("ok");
      // }
      // else if (tulos == 1){
      //   response.send("noMoney");
      // }
      // else if (tulos == 2){
      //   response.send("wronAcc");
      // }
      // else {
      //   response.send("error");
      // }
     }
  });
});

module.exports = router;