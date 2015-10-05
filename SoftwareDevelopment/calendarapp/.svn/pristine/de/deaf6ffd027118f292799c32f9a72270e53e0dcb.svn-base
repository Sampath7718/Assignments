package calendar_app; 


import java.sql.SQLException; 
import java.util.ArrayList;
import java.util.Date;


public class Calendar 
{ 
	Event[] events = new Event[1000]; 
	Event[] rpevents = new Event[1000];
//	RepeatingEvent[] repeating;
	int numYears; 
	int numberOfDays; 
	int count1 = 0;
	int count2 = 0;
	final String eventTable = "Events";  
	CalendarDB db;
	
	
	public Calendar() throws ClassNotFoundException, SQLException
	{
		
		db = new CalendarDB(); 

		db.createTable(eventTable); 
	
		
		
	}
	
	
	
	//makes new Event in the events array and adds it to the specified day 
	public  void createRepeatEvent(String name, String desc, String loc, boolean repeat, Date start, Date stop, int duration, int freq) throws SQLException
	{
		//duration = how many days, weeks, or months to repeat
		//frequency = how many times should the event repeat
		Date tempStart = start;
		Date tempStop = stop;
		
		
			
		if (freq == 0){	
		// frequency 1 = repeat daily	
			
			for(int i = 0; i < duration; i++){
				rpevents[count2] = new Event(name, desc, loc, repeat, tempStart, tempStop);
				if(!checkForConflict(rpevents[count2]))
				{
				db.addEvent(rpevents[count2], eventTable);
				tempStart.setDate(tempStart.getDate()+1);
				tempStop.setDate(tempStop.getDate()+1);
				//System.out.println("it worked"); 
				count2 ++;
				}
				else{
					rpevents[count2] = null; 
					System.out.println("There is a conflict with this event"); }
			}}
		
		else if (freq == 1){	
			// frequency 2 = repeat weekly
			 
				
				for(int i = 0; i > duration; i++){
					rpevents[count2] = new Event(name, desc, loc, repeat, start, stop);
					if(!checkForConflict(rpevents[count2])){
					db.addEvent(rpevents[count2], eventTable);
					tempStart.setDate(tempStart.getDate()+7);
					tempStop.setDate(tempStop.getDate()+7);
					count2++;}
					else {
						rpevents[count2] = null; 
						System.out.println("There is a conflict with this event"); }
			}}
		
		else if (freq == 2){	
			// frequency 3 = repeat monthly 
				
				for(int i = 0; i> duration; i++){
					rpevents[count2] = new Event(name, desc, loc, repeat, start, stop);
					if(!checkForConflict(rpevents[count2])){
					db.addEvent(rpevents[count2], eventTable);
					tempStart.setMonth(+1);
					tempStop.setMonth(+1);
					count2++;
					}
					else{
						rpevents[count2] = null;
						System.out.println("There is a conflict with this event"); 
					}
			}}
		else
			System.out.println("DIDN'T WORK YOU COWARD"); 
		
		
		
		}
		
	
	
	public void createEvent(String name, String desc, String loc, boolean repeat, Date start, Date stop) throws SQLException
	{
		
		
	events[count1] = new Event(name, desc, loc, repeat, start, stop);
	if(!checkForConflict(events[count2]))
	{
		
	db.addEvent(events[count2], eventTable);

	
	count1++;
	}
	else{
		events[count2] = null;
		System.out.println("There is a conflict with this date"); }
	}

	
	
	
	public void deleteEvent(String name, Date start) throws SQLException
	{
		for(int i = 0; i<count1; i++){
			if(events[i].getEventName() == name && events[i].getStartTime() == start){
				db.deleteSingleEventByName(eventTable, events[i]); 
				events[i] = null; 
			}
		}
	}
	
	public ArrayList<Event> getEventsForWeek(int y, int start, int month) throws SQLException
	{
		Date startDate = new Date(y, month, start);
		ArrayList<Event> result = new ArrayList<Event>(db.getEventsForWeek(eventTable, startDate)); 
		return result; 
	}
	//for use by the UI to get events for a single day
	public ArrayList<Event> getEventsForDay(int y, int d, int m) throws SQLException
	{

		db.createTable(eventTable);
		
		int year = y;
		int day = d;
		int month = m; 
		Date target = new Date(year, month, day);
		
		ArrayList<Event> result = new ArrayList<Event>(db.getEventsForDay(eventTable, target));
		return result;
	
	}
	public Event getSingleEvents(int y,int d, int m, String name) throws SQLException
	{
		int year = y;
		int day = d;
		int month = m-1; 
		Date target = new Date(year, month, day);
		ArrayList<Event> result = getEventsForDay( y,  d,  m); 
		for(int i=0;i<result.size();i++)
		{
			if(result.get(i).getEventName().equals(name))
				return result.get(i);
		}
		return null;
	}
	

	
	 public boolean isLeapYear(int year)
	 {
		 if( year % 4 == 0)
			 return true;
		 else 
			 return false; 
	 }
	


	

	// returns true if the 2 days are the same
	protected boolean isDayEqualToExistingEventDay(Date existing, Date incoming) {
		
		Date existingDay = new Date(existing.getYear(), existing.getMonth(), existing.getDate());
		Date incomingDay = new Date(incoming.getYear(), incoming.getMonth(), incoming.getDate());
		
		if(existingDay.compareTo(incomingDay) == 0)
			return true;
		else
			return false;
		
	}
	
	// returns true if there's conflict
	protected boolean checkForConflict(Event e) throws SQLException {
		
		Date dateBeingAddedStart = e.startTime;
		Date dateBeingAddedStop = e.stopTime;
		
		ArrayList<Event> currentEvents = db.getEventsForDay(eventTable, dateBeingAddedStart);
		
		for(int i = 0; i < currentEvents.size(); i++) {
			
			Date dateStarted = currentEvents.get(i).startTime;
			
			Date dateEnding = currentEvents.get(i).stopTime;
			
			// if the events are on the same day, check the times
			if(isDayEqualToExistingEventDay(dateBeingAddedStart, dateStarted)) {	 
				// if there's a conflict, return true
				if(compareTimes(dateBeingAddedStart, dateBeingAddedStop, dateStarted, dateEnding))
					return true;
			} // end if
		} // end for
		// if no conflicts, return false
		return false;
	} // end checkForConflict
	
	// returns true if time conflicts
	protected boolean compareTimes(Date eventBeingAddedStart, Date eventBeingAddedEnd,  Date currentDateStart, Date currentDateEnd) {
		
		int hourStartingBeingAdded = eventBeingAddedStart.getHours();
		int minutesStartingBeingAdded = eventBeingAddedStart.getMinutes();
		
		int hourEndingBeingAdded = eventBeingAddedEnd.getHours();
		int minutesEndingBeingAdded = eventBeingAddedEnd.getMinutes();
		
		int hourStarted = currentDateStart.getHours();
		int minutesStarted = currentDateStart.getMinutes();
		
		int hourEnding = currentDateEnd.getHours();
		int minutesEnding = currentDateEnd.getMinutes();
		
		// if incoming event starts in the same hour as starting of current that is an hour or less
		if(hourEnding == hourStarted && hourStarted == hourStartingBeingAdded) {
			
			if(minutesStartingBeingAdded <= minutesEnding && minutesStartingBeingAdded >= minutesStarted)
				return true;
			if(minutesStartingBeingAdded < minutesStarted && minutesEndingBeingAdded > minutesStarted)
				return true;
		} // end if
		
		// e.g. already have a 3-8 and trying to add a 5-7
		if(hourStartingBeingAdded >= hourStarted && hourEndingBeingAdded <= hourEnding)
			return true;
		
		// e.g. have a 3-8 and trying to add a 2-4
		if(hourEndingBeingAdded > hourStarted)
			return true;
		
		// e.g have 3:30-8 and try to add 2-3
		if(hourEndingBeingAdded == hourStarted && minutesEndingBeingAdded > minutesEnding) 
			return true;
		
			
		return false;	
	}} // end compareTimes
	

