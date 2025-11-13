import java.util.Scanner;

import com.daoimpl.AppointmentDaoImp;
import com.daoimpl.DoctorDaoImp;
import com.entities.AppointmentPojo;
import com.entities.DoctorPojo;
import com.service.ApointmentService;
import com.service.DoctorService;
import com.util.MenuList;
import com.util.NegativeValueNotAllowedException;

public class Program {
	private static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		DoctorDaoImp ddi = new DoctorDaoImp();
		AppointmentDaoImp adi = new AppointmentDaoImp();
		
		int choice = -1;
		while((choice = MenuList. menuList())!=0) {
			try {
				switch (choice) {
				case 1:
					DoctorPojo doc = DoctorService.acceptDoctor();
					ddi.addDoctor(doc);
					break;
					
				case 2:
					AppointmentPojo appointment = ApointmentService.acceptAppointmentPojo();
					adi.bookAppointment(appointment);
					break;
					
				case 3:
					System.out.println("Enter the Appointment Id : ");
					int id = sc.nextInt();
					adi.cancelAppointment(id);
					break;
				case 4:
					adi.viewAllAppointment();
					break;
					
				case 5:
					adi.viewAllUpcommintAppointment();
					break;
				
				case 6:
					adi.countEachDoctorAppointment();
					break;
				default:
					System.out.println("Invalid Choice!! Try again.");
				}
			} catch (NegativeValueNotAllowedException neg) {
				System.out.println("Custom Exception: "+ neg.getMessage());
			} catch (Exception e) {
//				e.printStackTrace();
				System.out.println("Something went wrong!!");
				break;
			}
		}
	}
}
