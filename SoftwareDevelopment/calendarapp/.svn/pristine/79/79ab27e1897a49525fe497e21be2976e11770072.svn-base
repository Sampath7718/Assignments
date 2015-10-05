package calendar_app;

import java.util.Date;

public class Event implements Comparable<Event>
{
	protected String eventDescription;		// Event description
	protected String eventLocation;			// Event location
	protected String eventName;				// Event name
	protected Date startTime;				// Date object representing event start
	protected Date stopTime;				// Date object representing event end
	protected int eventID;					// Event id
	protected boolean repeated;		 // Does the event repeat?
	protected int duration;
	
	//--------------------------------------------------------------------------------------
	// Constructor(s)
	//--------------------------------------------------------------------------------------
	public Event(String name, String desc, String loc, boolean repeat, Date start, Date stop) {
		setName(name);
		setDescription(desc);
		setLocation(loc);
		setStartTime(start);
		setStopTime(stop);
		repeated = repeat;
	}
	
	public Event(int id, String name, String desc, String loc, boolean repeat, Date start, Date stop) {
		setEventID(id);
		setName(name);
		setDescription(desc);
		setLocation(loc);
		setStartTime(start);
		setStopTime(stop);
		repeated = repeat;
	}
	
	//--------------------------------------------------------------------------------------
	// Mutator methods
	//--------------------------------------------------------------------------------------
	public void setName(String name) {
		eventName = name;
	}
	
	public void setEventID(int id) {
		eventID = id;
	}
	
	public void setDescription(String desc) {
		eventDescription = desc;
	}
	
	public void setLocation(String loc) {
		eventLocation = loc;
	}
	
	public void setStartTime(Date start) {
		startTime = start;
	}
	
	public void setStopTime(Date stop) {
		stopTime = stop;
	}
	
	//--------------------------------------------------------------------------------------
	// Accessor methods
	//--------------------------------------------------------------------------------------
	public String getEventName() {
		return eventName;
	}
	
	public String getEventDescription() {
		return eventDescription;
	}
	
	public String getEventLocation() {
		return eventLocation;
	}
	
	public Date getStartTime() {
		return startTime;
	}
	
	public Date getStopTime() {
		return stopTime;
	}
	
	public int getEventID() {
		return eventID;
	}
	
	public boolean isRepeated() {
		return repeated;
	}
	
	//--------------------------------------------------------------------------------------
	// Returns a String description of the event
	//--------------------------------------------------------------------------------------

	public String toString() {
		
		String result = "";
		
		
		result += "Event Name: " + getEventName() + "\n";
		result += "Event Start Time: " + getStartTime() + "\n";
		result += "Event End Time: " + getStopTime() + "\n";
		result += "Event Location: " + getEventLocation() + "\n";
		
		if(isRepeated()) {
			result += "This event is repeated.";
		}
		
		else {
			result += "This event is not repeated.";
		}
		
		return result;
	}
	
	public int compareTo(Event e) {
		return getStartTime().compareTo(e.getStartTime());
	}
}
