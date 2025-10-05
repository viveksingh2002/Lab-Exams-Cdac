import React, { useState, useEffect } from 'react'
import { toast } from 'react-toastify';
import { getAllProducts } from '../../services/product';
import { useNavigate } from 'react-router-dom';


function DisplayAll() {
  const [products, setProducts] = useState([])

  const navigate = useNavigate()

  const allProducts = async () => {
    const response = await getAllProducts()
    if (response.status == "success") {
      console.log(response.data);
      setProducts(response.data)
    } else {
      toast.error("Something went wrong")
    }
  }


  useEffect(() => {
    allProducts()
  }, [])


  // logout
  const onLogout = () => {
    sessionStorage.removeItem("role")
    sessionStorage.removeItem("userid")
    navigate("/login")
  }

  return (
    <div>
      <div className='container'>
        <h1 className='header-title'>ALL Products</h1>
        <div>
          <table className='table'>
            <thead>
              <tr>
                <th>P_ID</th>
                <th>P_NAME</th>
                <th>P_DESC</th>
                <th>P_QNTY</th>
                <th>P_PRICE</th>
                <th>User_Id</th>
              </tr>
            </thead>
            <tbody>
              {products.map((product) => {
                return (
                  <tr key={product.p_id}>
                    <td>{product.p_id}</td>
                    <td>{product.p_name}</td>
                    <td>{product.p_desc}</td>
                    <td>{product.p_qnty}</td>
                    <td>{product.p_price}</td>
                    <td>{product.user_id}</td>
                  </tr>
                )
              })}

            </tbody>
          </table>

          <div className='container d-flex justify-content-between mt-3'>
            <button onClick={onLogout} className='btn btn-danger'>Logout</button>
          </div>
        </div>
      </div>
    </div>
  )
}

export default DisplayAll