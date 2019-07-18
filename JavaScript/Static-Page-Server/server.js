const connect = require('connect');
const serveStatic = require('serve-static');
var port = 3000;
var app = connect();
app.use(serveStatic(__dirname)).listen(port);
console.log(`Connected via ${port}`);