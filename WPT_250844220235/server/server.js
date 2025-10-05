const express = require("express")
const cors = require("cors")

const userRouter = require("./routes/users")
const productRouter = require("./routes/products")


const app = express()


// middlewares
app.use(cors())
app.use(express.json())
app.use("/users", userRouter)
app.use("/products", productRouter)



app.listen(4000, "localhost", ()=>{
    console.log("server is running on port 4000");
})