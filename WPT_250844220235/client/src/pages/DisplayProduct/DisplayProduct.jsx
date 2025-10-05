import React, { useState, useEffect } from 'react'
import { toast } from 'react-toastify';
import { getProductsOfUser } from '../../services/product';
import { useNavigate } from 'react-router-dom';

function DisplayProduct() {
    const [products, setProducts] = useState([])
    
    const navigate = useNavigate()


    const Products = async () => {
        const user_id = sessionStorage.getItem("user_id");
        const response = await getProductsOfUser(user_id)
        if (response.status == "success") {
            console.log(response.data);
            setProducts(response.data)
        } else {
            toast.error("Something went wrong")
        }
    }


    useEffect(() => {
        Products()
    }, [])


    // logout
    const onLogout = ()=>{
        sessionStorage.removeItem("role")
        sessionStorage.removeItem("userid")
        navigate("/login")
    }

    // delete
    const onDelete = () => {
        
    }


    return (
        <div className='container'>
            <h1 className='header-title'>Products</h1>
            <div>
                <table className='table'>
                    <thead>
                        <tr>
                            <th>P_ID</th>
                            <th>P_NAME</th>
                            <th>P_DESC</th>
                            <th>P_QNTY</th>
                            <th>P_PRICE</th>
                            <th>DELETE</th>
                        </tr>
                    </thead>
                    <tbody>
                        {products.map((product) => {
                            return(
                                <tr  key={product.p_id}>
                                    <td>{product.p_id}</td>
                                    <td>{product.p_name}</td>
                                    <td>{product.p_desc}</td>
                                    <td>{product.p_qnty}</td>
                                    <td>{product.p_price}</td>
                                    <td><button className='btn btn-danger'>Delete</button></td>
                                </tr>
                            )
                        })}

                    </tbody>
                </table>

                <div className='container d-flex justify-content-between mt-3'>
                    <button onClick={()=>{
                        navigate("/add-product")
                    }} className='btn btn-secondary '>Add Product</button>
                    <button onClick={onLogout} className='btn btn-danger'>Logout</button>
                </div>
            </div>
        </div>
    )
}

export default DisplayProduct