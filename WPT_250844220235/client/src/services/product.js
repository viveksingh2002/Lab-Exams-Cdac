
import axios from 'axios';


export async function getProductsOfUser(user_id){

    const url = `http://localhost:4000/products/user/${user_id}`
    const response = await axios.get(url)
    console.log(response);
    return response.data
}

export async function addProduct(p_name, p_desc, p_qnty, p_price, user_id) {
    const url = `http://localhost:4000/products/user/add/${user_id}`
    const body = {p_name, p_desc, p_qnty, p_price}
    const response = await axios.post(url, body)
    console.log(response);
    return response.data
}

export async function getAllProducts(){

    const url = `http://localhost:4000/products/admin`
    const response = await axios.get(url)
    console.log(response);
    return response.data
}

export async function deleteProduct(p_id){
    const url = `http://localhost:4000/products/${pid}`
    const response = await axios.get(url)
    console.log(response);
    return response.data
}