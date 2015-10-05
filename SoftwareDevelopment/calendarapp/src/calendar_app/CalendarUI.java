package calendar_app;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Date;
import java.io.*;

public class CalendarUI
{
	Calendar calendar;
	String[] initialOptions;
	Scanner scan;
	BufferedReader read;
	boolean normalFlag;
	
	// Constructor
	public CalendarUI(boolean bool) throws Exception {
		normalFlag = bool;
		calendar = new Calendar();
		scan = new Scanner(System.in);
		read = new BufferedReader(new InputStreamReader(System.in));
		initialOptions = new String[5];
		initialOptions[0] = "View Events by Day";
		initialOptions[1] = "View Events by Week";
		initialOptions[2] = "Add Event to Calendar";
		initialOptions[3] = "Email Event to Another Calendar User";
		initialOptions[4] = "Exit the Program";
	}
	
	// Display method to be called by main()
	public void display() throws Exception {
		if(normalFlag) {
			displayInitMenu();
		}
		else {
			askForInitOption();
		}
	}
	
	// Display the initial options menu
	public void displayInitMenu() throws Exception {
		System.out.println("\n======================================================");
		System.out.println("                  Barracuda Calendar");
		System.out.println("======================================================\n");
		System.out.println("Welcome!\n");
		System.out.println("Here are your options:\n");
		
		for(int i = 0; i < initialOptions.length; i++) {
			System.out.println((i + 1) + ". " + initialOptions[i]);
		}
		
		System.out.println("");
		askForInitOption();
	}
	
	// Prompt user for an option in the initial menu
	public void askForInitOption() throws Exception {
		if(normalFlag) {
			System.out.print("Please enter the number of the option you choose: ");
		}
		
		int optionNum = scan.nextInt();
		
		if (optionNum > 0 && optionNum <= initialOptions.length) {
			runInitOption(optionNum);
		}
		else {
			System.out.println("\nThat wasn't a valid option. Please try again.\n");
			askForInitOption();
		}
	}
	
	// Run the option that the user selects
	public void runInitOption(int optionNum) throws Exception {
		switch(optionNum) {
			case 1: displayViewByDay();
					break;
			case 2: displayViewByWeek();
					break;
			case 3: displayAddEventInitMenu();
					break;
			case 4: displayEmailEventMenu();
			        break;
			case 5: exitProgram();
					break;
		}
	}
	
	// Prompt for a date
	public int[] promptForDate() throws Exception {
		int year, month, day;
		
		if(normalFlag) {
			System.out.print("Enter year (xxxx): "); 
			year = Integer.parseInt(read.readLine());
			System.out.print("Enter month (1-12): ");
			month = Integer.parseInt(read.readLine());
			System.out.print("Enter day of the month: "); 
			day = Integer.parseInt(read.readLine());
		}
		else {
			year = Integer.parseInt(read.readLine());
			month = Integer.parseInt(read.readLine());
			day = Integer.parseInt(read.readLine());
		}
		
		// These if/else if/else statements check the validity of the date
		if((month > 12 || month < 1) || (day >= 32 || day <= 0) || (day >= 29 && (month == 2 && !calendar.isLeapYear(year))) || 
				(day >= 30 && (month == 2 && calendar.isLeapYear(year))) || (day >= 31 && (month == 4 || month == 6 || 
				month == 9 || month == 11))) {
			System.out.println("\nThis is not a valid date. Please try again.\n");
			promptForDate();
		}
		else {
			int[] dateValues = {year, month, day};
			return dateValues;
		}
		
		return null;
	}
	
	// Prompt for the Event details
	public String[] promptForEventDetails() throws Exception {
		String name, desc, loc, rep;
		
		if(normalFlag) {
			System.out.print("Enter a name for the event: ");
			name = read.readLine();
			System.out.print("Enter a description for the event: ");
			desc = read.readLine();
			System.out.print("Enter an event location: ");
			loc = read.readLine();
		}
		else {
			 name = read.readLine();
			 desc = read.readLine();
			 loc = read.readLine();
		}
		
		String[] eventDetails = {name, desc, loc};
		return eventDetails;
	}
	
	// Prompt for event repeatability
	public boolean promptForRepeat() throws Exception {
		if(normalFlag) {
			System.out.print("Is this a repeating event? (Enter y/n): ");
		}
		
		String rep = read.readLine();
		
		if(!(rep.equalsIgnoreCase("y") || rep.equalsIgnoreCase("n"))) {
			System.out.println("That was not a valid y/n reponse. Please try again.");
			promptForRepeat();
		}
		else if(rep.equalsIgnoreCase("y")) {
			return true;
		}
		
		return false;
	}
	
	// Prompt for the start time of the event
	public int[] promptForStartTime() throws Exception {
		if(normalFlag) {
			System.out.print("Enter a starting time for the event (e.g. 22:30): ");
		}
		
		String time = read.readLine();
		
		if(!time.contains(":")) {
			System.out.println("That was an invalid time. Please try again.");
			promptForStartTime();
		}
		else {
			String[] div = time.split(":");
			int hours = Integer.parseInt(div[0]);
			int minutes = Integer.parseInt(div[1]);
			
			if(hours > 24 || hours < 1 || minutes > 60 || minutes < 0) {
				System.out.print("That was an invalid time. Please try again.");
				promptForStartTime();
			}
			else {
				int[] timeValues = {hours, minutes};
				return timeValues;
			}
		}
		
		return null;
	}
	
	// Prompt the end time of the event
	public int[] promptForEndTime() throws Exception {
		if(normalFlag) {
			System.out.print("Enter an ending time for the event (e.g. 23:30): ");
		}
		
		String time = read.readLine();
		
		if(!time.contains(":")) {
			System.out.println("That was an invalid time. Please try again.");
			promptForStartTime();
		}
		else {
			String[] div = time.split(":");
			int hours = Integer.parseInt(div[0]);
			int minutes = Integer.parseInt(div[1]);
			
			if(hours > 24 || hours < 1 || minutes > 60 || minutes < 0) {
				System.out.print("That was an invalid time. Please try again.");
				promptForStartTime();
			}
			else {
				int[] timeValues = {hours, minutes};
				return timeValues;
			}
		}
		
		return null;
	}
	
	// Prompt for the repeat details of the event
	public int[] promptForRepeatDetails() throws Exception {
		String freqString;
		int duration = 0;
		int freq = 0;
		
		if(normalFlag) {
			System.out.print("Should the event repeat daily, weekly, or monthly? (enter d, w, or m): ");
			freqString = read.readLine();
			System.out.print("For how many days/weeks/months should the event repeat? ");
			duration = Integer.parseInt(read.readLine());
		}
		else {
			freqString = read.readLine();
		}
		
		if(!(freqString.equalsIgnoreCase("d") || freqString.equalsIgnoreCase("w") || freqString.equalsIgnoreCase("m"))) {
			System.out.println("That was not a valid option. Please try again.");
			promptForRepeatDetails();
		}
		else if(freqString.equalsIgnoreCase("d")) {
			freq = 0;
		}
		else if(freqString.equalsIgnoreCase("w")) {
			freq = 1;
		}
		else if(freqString.equalsIgnoreCase("m")) {
			freq = 2;
		}
		
		int[] repeatDetails = {duration, freq};
		return repeatDetails;
	}
	
	// Prompt to return to the initial menu
	public void promptForInitMenu() throws Exception {
		if(normalFlag)
		{
			System.out.print("\nPress enter to go back to the main menu.");
			String next = read.readLine();
			if(next != null) {
				displayInitMenu();
			}
		}
	}
	
	// Prompt for a day and display the events for that day
	public void displayViewByDay() throws Exception {
		if(normalFlag)
		{
			System.out.println("\n=== View Events By Day ===");
			System.out.println("Enter the date for which you'd like to view events.\n");
		}
		int[] dateValues = promptForDate();
		int year = dateValues[0];
		int month = dateValues[1];
		int day = dateValues[2];
		
		ArrayList<Event> temp = new ArrayList<Event>(calendar.getEventsForDay(year, day, month));
		
		if(temp.size() > 0) {
			System.out.println("\n== Events for " + month + "/" + day + "/" + year + " ==\n");
			
			for(int i = 0; i < temp.size(); i++) {
				System.out.println(temp.get(i) + "\n");
			}
		}
		else {
			System.out.println("No events for " + month + "/" + day + "/" + year + ".");
		}
		
		promptForInitMenu();
	}
	
	// Prompt for a day and display the events for the week that day is in
	public void displayViewByWeek() {
		
	}
	
	// Display the menu to add an event
	public void displayAddEventInitMenu() throws Exception {
		if(normalFlag)
		{
			System.out.println("\n=== Add Event to Calendar ===");
			System.out.println("Please enter the details of the event as prompted.\n");
		}
		String[] eventDetails = promptForEventDetails();
		String name = eventDetails[0];
		String desc = eventDetails[1];
		String loc = eventDetails[2];
		
		int[] dateValues = promptForDate();
		int year = dateValues[0];
		int month = dateValues[1];
		int day = dateValues[2];
		
		int[] startTimeValues = promptForStartTime();
		int startHours = startTimeValues[0];
		int startMinutes = startTimeValues[1];
		
		int[] endTimeValues = promptForEndTime();
		int endHours = endTimeValues[0];
		int endMinutes = endTimeValues[1];

		boolean repeating = promptForRepeat();

		Date start = new Date(year, month, day, startHours, startMinutes);
		Date end = new Date(year, month, day, endHours, endMinutes);
		
		if(repeating == true) {
			int[] repeatDetails = promptForRepeatDetails();
			int duration = repeatDetails[0];
			int freq = repeatDetails[1];
			
			// Here, we're creating the event. The createRepeatEvent() and createEvent() methods in the Calendar class should 
			// be modified to return a boolean: true if the event was added, or false if there was some conflict
			
			// boolean addSuccess = calendar.createRepeatEvent(name, desc, loc, repeating, start, end, duration, freq);
			calendar.createRepeatEvent(name, desc, loc, repeating, start, end, duration, freq);
			// if(addSuccess) {
				System.out.println("Event added.");
			// }
			// else {
			//	System.out.println("Event was not added because some sort of error occurred.");
			// }
			
			// You get the point.
		}
		else {
			// Same thing here as above.
			
			calendar.createEvent(name, desc, loc, repeating, start, end);
			System.out.println("Event added.");
		}
		
		promptForInitMenu();
	}
	
	// Display the menu to email an event
	public void displayEmailEventMenu() throws Exception
	{
		String recipient;
		String message =" ";
		String subject;
		String details;
		Event e;
		int year;
		int month;
		int day;
		
		boolean answer;
		if(normalFlag==true)
		{
			System.out.println("Please enter the email of the recipient");
			  recipient=read.readLine();
			System.out.println("Please enter the subject of the message");
			  subject = read.readLine();
			  System.out.println("Please enter the name of the event you wish to send");
			  details = read.readLine();
			  System.out.println("Please enter the year the event would take place");
			  year = Integer.parseInt(read.readLine());
			  System.out.println("Please enter the month the event would take place");
			  month = Integer.parseInt(read.readLine());
			  System.out.println("Please enter the day the event would take place");
			  day =Integer.parseInt(read.readLine());
		}
		else
		{
			recipient=read.readLine();
			subject = read.readLine();
			details = read.readLine();
			year = Integer.parseInt(read.readLine());
			 month = Integer.parseInt(read.readLine());
			 day =Integer.parseInt(read.readLine());
		}
		Calendar cal=new Calendar();
		
		   e=cal.getSingleEvents(year, day, month, details);
		   if(e!=null)
		      message="Event Name: "+e.getEventName()+"\nEvent Location: "+e.getEventLocation()+"\nEvent Description: "+e.getEventDescription()+
		    		  "\nEvent Start Time: "+e.getStartTime()+"\nEvent End Time: "+e.getStopTime() ;
			message+="\nIf you want to add this event to your calendar, copy and paste the characteristics of the event in a file called " +
					"\"Event.txt\" in the home directory" ;
			
			Emailer email=new Emailer("barracudas387@gmail.com","barracudas12");
			
			email.sendMail(recipient, subject, message);
			
		
	}
	
	// Exit the program
	public void exitProgram() {
		System.out.println("\nBye!");
		System.exit(1);
	}
}
