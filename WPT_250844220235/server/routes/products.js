const express = require("express")
const pool = require("../util/db")
const result = require("../util/result")

const router = express.Router()

// for users
router.get("/user/:user_id", (req, res) => {
    const { user_id } = req.params
    const sql = "Select * from products where user_id = ?"
    pool.query(sql, [user_id], (error, data) => {
        res.send(result.createResult(error, data))
    })
})

router.post("/user/add/:user_id", (req, res) => {
    const { user_id } = req.params
    const { p_name, p_desc, p_qnty, p_price } = req.body
    const sql = `insert into products(p_name, p_desc, p_qnty, p_price, user_id) values(?, ?, ?, ?, ?)`

    pool.query(sql, [p_name, p_desc, p_qnty, p_price, user_id], (error, data) => {
        if (data) {
            console.log("product added successfully");
            res.send(result.createResult(error, data))
        } else {
            res.send(result.createResult(error, data))
        }
    })

})

router.delete("/:p_id", (req, res) => {
    const { p_id } = req.params
    const sql = `DELETE FROM products where p_id = ?`

    pool.query(sql, [p_id], (error, data) => {

        console.log("product deleteted successfully");
        res.send(result.createResult(error, data))

    })

})

// for admin
router.get("/admin", (req, res) => {
    const sql = "Select * from products"
    pool.query(sql, (error, data) => {
        res.send(result.createResult(error, data))
    })
})

module.exports = router
