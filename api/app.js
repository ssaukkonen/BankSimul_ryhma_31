var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var customerRouter = require('./routes/customer');
var actionsRouter = require('./routes/actions');
var future_actionsRouter = require('./routes/future_actions');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/customer', customerRouter);
app.use('/actions', actionsRouter);
app.use('/future_actions', future_actionsRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);

module.exports = app;
