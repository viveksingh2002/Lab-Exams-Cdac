using DotNetLabExam.Models;
using Microsoft.AspNetCore.Mvc;

namespace DotNetLabExam.Controllers
{

    //UserDBContext context = new UserDBContext();
    public class LoginController : Controller
    {
        [HttpGet]
        public IActionResult SignIn()
        { 
            return View(); 
        }

        [HttpPost]
        public IActionResult SignIN(User user)
        {   
            if(user.UserName == "User" && user.Password == "test@123")
            {
                return Redirect("/Home/Index");
            }
            else
            {
                return Redirect("/Login/SignIn");
            }

        }

        public IActionResult Logout()
        {
            return Redirect("/Login/SignIn");
        }
        
    }
}
