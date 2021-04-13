const express = require('express');
const router = express.Router();
const card = require('../models/card_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    card.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
  else {
       card.getAll(function(err, dbResult) {
     if (err) {
       response.json(err);
     } else {
       response.json(dbResult);
      }
    });
  }
});


router.post('/', 
function(request, response) {
  card.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.post('/card_number', 
function(request, response) {
  card.card_number(request.body.card_number, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult[0]);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  card.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  card.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;