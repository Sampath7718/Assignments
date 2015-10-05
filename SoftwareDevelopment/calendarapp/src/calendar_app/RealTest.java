package calendar_app;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Date;

public class RealTest {
	
public static void main(String[] args) throws ClassNotFoundException, SQLException {
		
		CalendarDB myDB = new CalendarDB();
		
		myDB.createTable("NewTable");
		
		Date today = new Date(114,3,15,8,21,44);
		Date tomorrow = new Date(114,3,20,7,21,11);
		
		Event doctorAppointment = new Event("appointment", "blah blah desc", "my house", false, today, tomorrow);
		
		myDB.addEvent(doctorAppointment, "NewTable");
		
		System.out.print(myDB.getSingleEventByName("NewTable", "appointment").toString());
		
	/*	ArrayList<Event> allEvents = new ArrayList<Event>(myDB.getAllEvents("NewTable"));
		for(int i = 0; i < allEvents.size(); i++) {
			System.out.print(allEvents.get(i).toString() + "\n\n");
		} */
		
	//	myDB.deleteSingleEventByName("NewTable", doctorAppointment);
		
	//	myDB.clearAllEvents("NewTable");
	






}
}