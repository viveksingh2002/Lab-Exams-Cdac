
import axios from 'axios';

export async function getLogin(username, password, role) {
    const url = "http://localhost:4000/users/login"
    const body = {username, password, role}
    console.log("body", body);
    const response = await axios.post(url, body)

    return response.data
}