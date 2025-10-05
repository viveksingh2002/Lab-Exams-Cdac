import React from 'react'
import { useState} from 'react'
import { Link, useNavigate } from 'react-router-dom'
import { addProduct } from '../../services/product'
import { toast } from 'react-toastify'

function AddProduct() {
     
    const [p_name, setP_name] = useState("")
    const [p_desc, setP_desc] = useState("")
    const [p_qnty, setP_Qnty] = useState(0)
    const [p_price, setP_price] = useState(0)

    const navigate = useNavigate()
   
    const onAddProduct = async ()=>{
        const user_id = sessionStorage.getItem("user_id")
        const response = await addProduct(p_name, p_desc, p_qnty, p_price, user_id)
        console.log(response);
        if(response.status == "success"){
            toast.success("product added successfully")
            navigate("/display-product")
        }else{
            toast.error(response.error)
        }
    }

    return (
        <div className='container'>
            <h1 className='header-title my-2'>ADD PRODUCT</h1>
            <div className='border rounded-3 p-5 my-3'>
                <div className=' mb-3'>
                    <label htmlFor="inputUser">P_Name</label>
                    <input onChange={(e) => {
                        setP_name(e.target.value)
                    }} className='form-control' type="text" id='inputUser' />
                </div>
                <div className='mb-3'>
                    <label htmlFor="inputPassword">P_Desc</label>
                    <input onChange={(e) => {
                        setP_desc(e.target.value)
                    }} className='form-control' type="text" id='inputPassword' />
                </div>
                <div className='mb-3'>
                    <label htmlFor="inputPassword">P_Qnty</label>
                    <input onChange={(e) => {
                        setP_Qnty(e.target.value)
                    }} className='form-control' type="text" id='inputPassword' />
                </div>
                <div className='mb-3'>
                    <label htmlFor="inputPassword">P_Price</label>
                    <input onChange={(e) => {
                        setP_price(e.target.value)
                    }} className='form-control' type="text" id='inputPassword' />
                </div>
                <div className='mb-3 align-center'>
                    <button onClick={onAddProduct} className='btn btn-success'>Add</button>
                </div>
            </div>
        </div>
    )
}

export default AddProduct