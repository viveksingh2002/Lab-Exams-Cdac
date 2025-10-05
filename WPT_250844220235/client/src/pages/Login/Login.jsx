import React, { useState } from 'react'
import { Link, useNavigate } from 'react-router-dom'
import { getLogin } from '../../services/login'

function Login() {
    const [ username, setUsername ] = useState("")
    const [ password, setPassword ] = useState("")
    const [ role, setRole ] = useState("")

    const navigate = useNavigate()

    const onLogin =  async ()=>{
        const response = await getLogin(username, password, role)
        console.log(response);
        if(response.status=="success"){
            alert("login successfull")

            sessionStorage.setItem("user_id", response.data.user_id)
            sessionStorage.setItem("role", role)
            
            if(role.toLowerCase() == "user"){
                navigate("/display-product")
            }else{

                navigate("/display-all")
            }
        }else{
            alert("Invalid username/password")
        }
    }


    return (
        <div className='container'>
            <h1 className='header-title my-2'>Login</h1>
            <div className='border rounded-3 p-5 my-3'>
                <div className=' mb-3'>
                    <label htmlFor="inputUser">UserName</label>
                    <input onChange={(e)=>{
                        setUsername(e.target.value)
                    }} className='form-control' type="text" id='inputUser' />
                </div>
                <div className='mb-3'>
                    <label htmlFor="inputPassword">Password</label>
                    <input onChange={(e)=>{
                        setPassword(e.target.value)
                    }} className='form-control' type="password" id='inputPassword' />
                </div>
                <div className='mb-3'>
                    <label htmlFor="inputRole">Role: (ADMIN, USER)</label>
                    <input onChange={(e)=>{
                        setRole(e.target.value)
                    }} className='form-control' type="text" id='inputRole' />
                </div>
                <div className='mb-3'>
                    <button onClick={onLogin} className='btn btn-success'>Login</button>
                </div>
            </div>
        </div>
    )
}

export default Login