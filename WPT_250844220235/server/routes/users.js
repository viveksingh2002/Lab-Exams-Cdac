const express = require("express")
const pool = require("../util/db")
const result = require("../util/result")

const router = express.Router()

//
router.post("/login", (req, res) => {

    console.log(req.body);

    const { username, password, role } = req.body
    const sql = `Select * from users where username = ?`
    pool.query(sql, [username], (error, data) => {
        if (data != "") {
            userData = data[0]
            console.log(userData)
            if (userData.password == password) {
                console.log("login successfull");
                res.send(result.createResult(error, userData))
            }

        } else {
            res.send("Invadid username!")
        }
    })

})





module.exports = router