const mysql = require("mysql2")

const pool = mysql.createPool({
    host:"localhost",
    user:"root",
    password:"root",
    database:"db_cdac"
})

module.exports = pool