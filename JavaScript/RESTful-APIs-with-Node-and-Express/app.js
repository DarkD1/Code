const express = require('express');
const Joi = require('joi');
const app = express();
app.use(express.json());

const port = process.env.PORT || 3000;
const customers = [ {id: 17081, name: 'Sazzad Hossain'}, 
                    {id: 17099, name: 'Ahadul Islam'},
                    {id: 17090, name: 'Saidur Rahman'},
                    {id: 17045, name: 'Saiful Islam'}];

// GET Operations
app.get('/', (req, res) => {
    res.send('Hello World!!');
});
app.get('/api/customers', (req, res) => {
    res.send(customers);
});
app.get('/api/customers/:id', (req, res) => {
    const customer = customers.find(c => c.id === parseInt(req.params.id));
    if(!customer){
        res.status(404).send("No customer with that id");
    }else{
        res.send(customer);
    }
});
// POST Operation
app.post('/api/customers', (req, res) => {
    // ERROR HANDLING FOR POST REQUEST
    const {error} = validateInput(req.body);
    if(error){
        res.status(400).send(error.details[0].message);
        return;
    }
    // NO ERROR 
    const customer = {id: req.body.id, name: req.body.name};
    customers.push(customer);
    res.send(customer);
});
// PUT Operation
app.put('/api/customers/:id', (req, res) => {
    const customer = customers.find(c => c.id === parseInt(req.params.id));
    if(!customer){
        res.status(404).send("No customer with that id");
        return;
    }
    const {error} = validateInput(req.body);
    if(error){
        res.status(400).send(error.details[0].message);
        return;
    }
    customer.name = req.body.name;
    res.send(customer);
});

app.delete('/api/customers/:id', (req, res) =>{
    const customer = customers.find(c => c.id === parseInt(req.params.id));
    if(!customer){
        res.status(404).send("No customer with that id");
        return;
    }
    const index = customers.indexOf(customer);
    customers.splice(index, 1);
    res.send(customer);
});

function validateInput(customer){
    const schema = {
        name: Joi.string().min(5).required()
    };
    return Joi.validate(customer, schema);
}

app.listen(port, () => console.log(`Listening on port ${port}`));

