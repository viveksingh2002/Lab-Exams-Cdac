using System.Diagnostics;
using DotNetLabExam.Models;
using Microsoft.AspNetCore.Mvc;

namespace DotNetLabExam.Controllers
{
    public class HomeController : Controller
    {
        FirDBContext context = new FirDBContext();
        public IActionResult Index()
        {
            List<Fir> firLst  = context.GetAllFirs();
            return View(firLst); 
        }

        [HttpGet]
        public IActionResult Register()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Register(Fir fir)
        {
            context.RegisterFir(fir);
            return Redirect("/Home/Index");
        }


        [HttpGet]
        public IActionResult Update(int id)
        {
            Fir fir = context.GetFirById(id);
            return View(fir);
        }

        [HttpPost]
        public IActionResult Update(Fir fir)
        {
            context.UpdateFir(fir);
            return Redirect("/Home/Index");
        }


    }
}
