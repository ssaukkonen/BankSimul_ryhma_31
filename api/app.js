var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var customerRouter = require('./routes/customer');
var customer_accountRouter = require('./routes/customer_account');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/customer', customerRouter);
app.use('/customer_account', customer_accountRouter);

module.exports = app;
