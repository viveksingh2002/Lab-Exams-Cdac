using Microsoft.Data.SqlClient;

namespace DotNetLabExam.Models
{
    public class FirDBContext
    {
        
        public List<Fir> GetAllFirs()
        {
            string connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=db_gogo;Integrated Security=True;Encrypt=True";

            SqlConnection con = new SqlConnection(connectionString);
            con.Open();

            SqlCommand cmd = new SqlCommand("Select * from FirTB", con);
            SqlDataReader reader = cmd.ExecuteReader();

            List<Fir> firLst = new List<Fir>();

            while (reader.Read())
            {
                Fir fir = new Fir();
                fir.Id = Convert.ToInt32(reader["Id"]);
                fir.Complainant = reader["Complainant"].ToString();
                fir.Mobile = reader["Mob_No"].ToString();
                fir.FirType = reader["Fir_Type"].ToString();
                fir.Status = reader["Status"].ToString();
                fir.Date = reader["Date"].ToString().Split()[0];

                firLst.Add(fir);
            }
            con.Close();

            return firLst;

        }

        public int RegisterFir(Fir fir)
        {
            string connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=db_gogo;Integrated Security=True;Encrypt=True";

            SqlConnection con = new SqlConnection(connectionString);
            con.Open();

            string stmt = "insert into FirTB(Complainant, Mob_No, Fir_Type, Status, Date) values('{0}','{1}','{2}','{3}','{4}')";
            string formattedString = string.Format(stmt, fir.Complainant, fir.Mobile, fir.FirType, "Pending", fir.Date.ToString());

            SqlCommand cmd = new SqlCommand(formattedString, con);
            int affectedRows = cmd.ExecuteNonQuery();
            con.Close();

            return affectedRows;
        }

        public Fir GetFirById(int id)
        {
            List<Fir> firlst = GetAllFirs();
            foreach(var fir in firlst)
            {
                if(fir.Id == id)
                {
                    return fir;
                }
            }
            return null;
        }

        public int UpdateFir(Fir fir)
        {
            string connectionString = "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=db_gogo;Integrated Security=True;Encrypt=True";

            SqlConnection con = new SqlConnection(connectionString);
            con.Open();

            string stmt = "update FirTB set Complainant = '{1}', Mob_No = '{2}', Fir_Type = '{3}', Status= '{4}' where id={0}";
            string formattedString = string.Format(stmt, fir.Id, fir.Complainant, fir.Mobile, fir.FirType, fir.Status);

            Console.WriteLine(formattedString);

            SqlCommand cmd = new SqlCommand(formattedString, con);
            int affectedRows = cmd.ExecuteNonQuery();
            con.Close();

            return affectedRows;

        }

        

    }
}
