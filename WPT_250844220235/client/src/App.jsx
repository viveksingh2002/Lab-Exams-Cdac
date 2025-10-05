import {Navigate, Routes, Route} from "react-router-dom"
// Import {ToastContainer} from react-to
import './App.css'

import Login from './pages/Login/Login';
import AddProduct from './pages/AddProduct/AddProduct';
import DisplayProduct from './pages/DisplayProduct/DisplayProduct';
import DisplayAll from './pages/DisplayAll/DisplayAll';


function App() {

  return (
    <div>

      <Routes>

      <Route path="/" element={<Navigate to="/login" />} />
      <Route path="login" element={<Login />} />
      <Route path="add-product" element={<AddProduct />} />
      <Route path="display-product" element={<DisplayProduct />} />
      <Route path="display-all" element={<DisplayAll />} />

      </Routes>
      

    </div>
  )
}

export default App
