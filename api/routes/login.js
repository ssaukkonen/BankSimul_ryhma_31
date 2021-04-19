const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

router.post('/', 
  function(request, response) {
    if(request.body.username && request.body.password){
      const username = request.body.username;
      const password = request.body.password;
      login.checkPassword(username, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              if (dbResult[0].locked < 3){   
              bcrypt.compare(password,dbResult[0].pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("success");
                  const id_card=dbResult[0].id_card;
                  login.updateCorrectPass(id_card, function(err, dbResult) {
                    if (err) {
                      response.json(err);
                    } else {
                      console.log("locked reset");;
                    }
                  })
                  response.send(true);
                }
                else {
                    console.log("wrong password");
                    const id_card=dbResult[0].id_card;
                    console.log(id_card);
                    login.updateWrongPass(id_card, function(err, dbResult) {
                      if (err) {
                        response.json(err);
                      } else {
                        console.log("locked updated");;
                      }
                    })
                      response.send(false);
              }			
              }
              );
            }
            else if (dbResult[0].locked == 3) {
              console.log("pin locked")
              response.send("locked");
            }
          }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("username or password missing");
      response.send(false);
    }
  }
);

module.exports=router;