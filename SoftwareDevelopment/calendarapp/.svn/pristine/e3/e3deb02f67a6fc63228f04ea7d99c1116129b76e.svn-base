package calendar_app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Date;

public class CalendarDB {
	
	Connection dbConnection;
	Statement dbStatement;
	String eName, eDescription, eLocation, tableName, currentEventRepeating, eStartDate, eEndDate;
	int eTotalTime, eID, repeatingEvent;
	int eStartDay, eStartMonth, eStartYear, eStartMin, eStartHour;
	int eEndDay, eEndMonth, eEndYear, eEndMin, eEndHour;
	boolean eRepeated;
	
	
	public CalendarDB() throws ClassNotFoundException, SQLException {
		
		Class.forName("org.sqlite.JDBC");
		dbConnection =  DriverManager.getConnection("jdbc:sqlite:calendar387.db");
		dbStatement = dbConnection.createStatement();
		dbStatement.setQueryTimeout(45);
	}
	
	public void createTable(String name) {
		
		
		String makeTable = "create table if not exists " + name + 	"(eventID integer PRIMARY KEY," +
																	"eventName string,eventDescription string," +
																	"eventStartDay int," + "eventStartMonth int," +
																	"eventStartYear int," + "eventStartHour int, eventStartMinutes int," +
																	"eventEndDay int," + "eventEndMonth int," + "eventEndYear int," +
																	"eventEndHour int, eventEndMinutes int," +
																	"eventTotalTime int,eventLocation string," +
																	"isEventRepeated int)";
		try {
			dbStatement.executeUpdate(makeTable);
		}catch(SQLException e) {
			e.printStackTrace();
		}
	} // end createTable
	
	@SuppressWarnings("deprecation")
	public boolean addEvent(Event e, String tblName) throws SQLException {
	
		eName = e.getEventName();
		eDescription = e.getEventDescription();
		eLocation = e.getEventLocation();
		
		eStartDay = e.startTime.getDate();
		eStartMonth = e.startTime.getMonth();
		eStartYear = e.startTime.getYear();
		eStartMin = e.startTime.getMinutes();
		eStartHour = e.startTime.getHours();
		
		eEndDay = e.stopTime.getDate();
		eEndMonth = e.stopTime.getMonth();
		eEndYear = e.stopTime.getYear();
		eEndMin = e.stopTime.getMinutes();
		eEndHour = e.stopTime.getHours();
		
		if(e.repeated == false)
			repeatingEvent = 0;
		else if(e.repeated == true)
			repeatingEvent = 1;
		
		String insert = "insert into " + tblName + 	"(eventName,eventDescription,eventStartDay," +
														"eventStartMonth, eventStartYear, eventStartHour, eventStartMinutes, " +
														"eventEndDay, eventEndMonth, eventEndYear, eventEndHour, eventEndMinutes," +
														"eventTotalTime,eventLocation, isEventRepeated)" +
														" values('" + eName + "','" + eDescription + "','" + 
														eStartDay + "','" + eStartMonth + "','" + eStartYear +
														"','" + eStartHour + "','" + eStartMin + "','" + eEndDay +
														"','" + eEndMonth + "','" + eEndYear + "','" + eEndHour + "','" 
														+ eEndMin + "','" + eTotalTime + "','" + eLocation + "','" +
														repeatingEvent + "')";
		
		if(dbStatement.executeUpdate(insert) == 0) {
			return false;
		}
		else
			return true;
	} // end addRecord 
	
	@SuppressWarnings("deprecation")
	public Event getSingleEventByName(String tblName, String nameToGet) throws SQLException {
		
		Event queryResult = null;
		
		ResultSet dbOutput = dbStatement.executeQuery("select * from " + tblName + " where eventName='" + nameToGet + "'");
		
		while(dbOutput.next()) {
			
			if(dbOutput.getInt("isEventRepeated") == 0) {
				eRepeated = false;
			}
			else if(dbOutput.getInt("isEventRepeated") == 1) {
				eRepeated = true;
			}
			
			
			
			eID = dbOutput.getInt("eventID");
			eName = dbOutput.getString("eventName");
			eDescription = dbOutput.getString("eventDescription");
			eTotalTime = dbOutput.getInt("eventTotalTime");
			eLocation = dbOutput.getString("eventLocation");
			eStartDay = dbOutput.getInt("eventStartDay");
			eStartMonth = dbOutput.getInt("eventStartMonth");
			eStartYear = dbOutput.getInt("eventStartYear");
			eStartHour = dbOutput.getInt("eventStartHour");
			eStartMin = dbOutput.getInt("eventStartMinutes");
			eEndDay = dbOutput.getInt("eventEndDay");
			eEndMonth = dbOutput.getInt("eventEndMonth");
			eEndYear = dbOutput.getInt("eventEndYear");
			eEndHour = dbOutput.getInt("eventEndHour");
			eEndMin = dbOutput.getInt("eventEndMinutes");
			
			Date startTime = new Date(eStartYear-1900, eStartMonth-1, eStartDay, eStartHour, eStartMin, 0);
			Date stopTime = new Date(eEndYear-1900, eEndMonth-1, eEndDay, eEndHour, eEndMin, 0);
					
			queryResult = new Event(eID, eName,eDescription,eLocation,eRepeated,startTime,stopTime);
		//	queryResult = new Event(eID, eName,eDescription,eLocation,eRepeated,eStartDay, eStartMonth,eStartYear,eStartTime,eEndDay,eEndMonth,eEndYear,eEndTime);
		}
		return queryResult;
	} // end getSingleRecord
	
	@SuppressWarnings("deprecation")
	public Event getSingleEventByTime(String tblName, Event e) throws SQLException {
		
		Event queryResult = null;
		
		int startYear = e.startTime.getYear();
		int startMonth = e.startTime.getMonth();
		int startDay = e.startTime.getDate();
		int startHour = e.startTime.getHours();
		int startMins = e.startTime.getMinutes();
		
		ResultSet dbOutput = dbStatement.executeQuery("select * from " + tblName + " where eventStartYear='" + startYear + "' AND" +
							 						  " eventStartMonth='" + startMonth + "' AND eventStartDay='" + startDay + 
							 						  "' AND eventStartHour='" + startHour + "' AND eventStartMinutes='" + startMins + "'");
		
		while(dbOutput.next()) {
			
			if(dbOutput.getInt("isEventRepeated") == 0) {
				eRepeated = false;
			}
			else if(dbOutput.getInt("isEventRepeated") == 1) {
				eRepeated = true;
			}
			
			eID = dbOutput.getInt("eventID");
			eName = dbOutput.getString("eventName");
			eDescription = dbOutput.getString("eventDescription");
			eTotalTime = dbOutput.getInt("eventTotalTime");
			eLocation = dbOutput.getString("eventLocation");
			eStartDay = dbOutput.getInt("eventStartDay");
			eStartMonth = dbOutput.getInt("eventStartMonth");
			eStartYear = dbOutput.getInt("eventStartYear");
			eStartHour = dbOutput.getInt("eventStartHour");
			eStartMin = dbOutput.getInt("eventStartMinutes");
			eEndDay = dbOutput.getInt("eventEndDay");
			eEndMonth = dbOutput.getInt("eventEndMonth");
			eEndYear = dbOutput.getInt("eventEndYear");
			eEndHour = dbOutput.getInt("eventEndHour");
			eEndMin = dbOutput.getInt("eventEndMinutes");
			
			Date startTime = new Date(eStartYear-1900, eStartMonth-1, eStartDay, eStartHour, eStartMin, 0);
			Date stopTime = new Date(eEndYear-1900, eEndMonth-1, eEndDay, eEndHour, eEndMin, 0);
		
					
			queryResult = new Event(eID, eName,eDescription,eLocation,eRepeated,startTime,stopTime);
		}
		return queryResult;
	}
	
	@SuppressWarnings("deprecation")
	public Event getSingleEventByID(String tblName, Event e) throws SQLException {
		
		int idToGet = e.getEventID();
		Event queryResult = null;
		
		ResultSet dbOutput = dbStatement.executeQuery("select * from " + tblName + " where eventID='" + idToGet + "'");
		
		while(dbOutput.next()) {
			
			if(dbOutput.getInt("isEventRepeated") == 0) {
				eRepeated = false;
			}
			else if(dbOutput.getInt("isEventRepeated") == 1) {
				eRepeated = true;
			}
			
			eID = dbOutput.getInt("eventID");
			eName = dbOutput.getString("eventName");
			eDescription = dbOutput.getString("eventDescription");
			eTotalTime = dbOutput.getInt("eventTotalTime");
			eLocation = dbOutput.getString("eventLocation");
			eStartDay = dbOutput.getInt("eventStartDay");
			eStartMonth = dbOutput.getInt("eventStartMonth");
			eStartYear = dbOutput.getInt("eventStartYear");
			eStartHour = dbOutput.getInt("eventStartHour");
			eStartMin = dbOutput.getInt("eventStartMinutes");
			eEndDay = dbOutput.getInt("eventEndDay");
			eEndMonth = dbOutput.getInt("eventEndMonth");
			eEndYear = dbOutput.getInt("eventEndYear");
			eEndHour = dbOutput.getInt("eventEndHour");
			eEndMin = dbOutput.getInt("eventEndMinutes");
			
			Date startTime = new Date(eStartYear-1900, eStartMonth-1, eStartDay, eStartHour, eStartMin, 0);
			Date stopTime = new Date(eEndYear-1900, eEndMonth-1, eEndDay, eEndHour, eEndMin, 0);
		
					
			queryResult = new Event(eID, eName,eDescription,eLocation,eRepeated,startTime,stopTime);
		}
		return queryResult;
	} // end getEventByID
	
	@SuppressWarnings("deprecation")
	public ArrayList<Event> getEventsForDay(String tblName, Date target) throws SQLException {
		
		ArrayList<Event> result = new ArrayList<Event>();
		
		int tarYear = target.getYear();
		int tarMonth = target.getMonth();
		int tarDay = target.getDate();
		
		ResultSet dbOutput = dbStatement.executeQuery("select * from " + tblName + " where eventStartYear='" + tarYear + "' AND" +
				  " eventStartMonth='" + tarMonth + "' AND eventStartDay='" + tarDay + "'"); 
		
		while(dbOutput.next()) {
			
			if(dbOutput.getInt("isEventRepeated") == 0) {
				eRepeated = false;
			}
			else if(dbOutput.getInt("isEventRepeated") == 1) {
				eRepeated = true;
			}
			
			eID = dbOutput.getInt("eventID");
			eName = dbOutput.getString("eventName");
			eDescription = dbOutput.getString("eventDescription");
			eTotalTime = dbOutput.getInt("eventTotalTime");
			eLocation = dbOutput.getString("eventLocation");
			eStartDay = dbOutput.getInt("eventStartDay");
			eStartMonth = dbOutput.getInt("eventStartMonth");
			eStartYear = dbOutput.getInt("eventStartYear");
			eStartHour = dbOutput.getInt("eventStartHour");
			eStartMin = dbOutput.getInt("eventStartMinutes");
			eEndDay = dbOutput.getInt("eventEndDay");
			eEndMonth = dbOutput.getInt("eventEndMonth");
			eEndYear = dbOutput.getInt("eventEndYear");
			eEndHour = dbOutput.getInt("eventEndHour");
			eEndMin = dbOutput.getInt("eventEndMinutes");
			
			Date startTime = new Date(eStartYear-1900, eStartMonth-1, eStartDay, eStartHour, eStartMin, 0);
			Date stopTime = new Date(eEndYear-1900, eEndMonth-1, eEndDay, eEndHour, eEndMin, 0);
		
					
			Event tempEvent = new Event(eID, eName,eDescription,eLocation,eRepeated,startTime,stopTime);
			result.add(tempEvent);
		}
		return result;
		
		
	}
	
	@SuppressWarnings("deprecation")
	public void getEventsForDay(String tblName, Date target, ArrayList<Event> listToAddTo) throws SQLException {
			
		int tarYear = target.getYear();
		int tarMonth = target.getMonth();
		int tarDay = target.getDate();
		
		ResultSet dbOutput = dbStatement.executeQuery("select * from " + tblName + " where eventStartYear='" + tarYear + "' AND" +
				  " eventStartMonth='" + tarMonth + "' AND eventStartDay='" + tarDay + "'"); 
		
		while(dbOutput.next()) {
			
			if(dbOutput.getInt("isEventRepeated") == 0) {
				eRepeated = false;
			}
			else if(dbOutput.getInt("isEventRepeated") == 1) {
				eRepeated = true;
			}
			
			eID = dbOutput.getInt("eventID");
			eName = dbOutput.getString("eventName");
			eDescription = dbOutput.getString("eventDescription");
			eTotalTime = dbOutput.getInt("eventTotalTime");
			eLocation = dbOutput.getString("eventLocation");
			eStartDay = dbOutput.getInt("eventStartDay");
			eStartMonth = dbOutput.getInt("eventStartMonth");
			eStartYear = dbOutput.getInt("eventStartYear");
			eStartHour = dbOutput.getInt("eventStartHour");
			eStartMin = dbOutput.getInt("eventStartMinutes");
			eEndDay = dbOutput.getInt("eventEndDay");
			eEndMonth = dbOutput.getInt("eventEndMonth");
			eEndYear = dbOutput.getInt("eventEndYear");
			eEndHour = dbOutput.getInt("eventEndHour");
			eEndMin = dbOutput.getInt("eventEndMinutes");
			
			Date startTime = new Date(eStartYear-1900, eStartMonth-1, eStartDay, eStartHour, eStartMin, 0);
			Date stopTime = new Date(eEndYear-1900, eEndMonth-1, eEndDay, eEndHour, eEndMin, 0);
		
					
			Event tempEvent = new Event(eID, eName,eDescription,eLocation,eRepeated,startTime,stopTime);
			listToAddTo.add(tempEvent);
		}

				
	}
	
	@SuppressWarnings("deprecation")
	public ArrayList<Event> getEventsForWeek(String tblName, Date startOfWeek) throws SQLException {
		
		ArrayList<Event> eventsForWeek = new ArrayList<Event>();
		
		for(int i = 0; i < 7; i++) {
			
			getEventsForDay(tblName, startOfWeek, eventsForWeek);
			
			int  currentDate = startOfWeek.getDate();
			int currentMonth = startOfWeek.getMonth();
			
			// if always has to be +1
			if(currentDate < 28) {
				startOfWeek.setDate(currentDate + 1);
			}
			
			// if february and leap year
			else if(startOfWeek.getMonth() == 1) {
				// if leap year and on 28th day
				if(startOfWeek.getYear() % 4 == 0 && currentDate < 29)
					startOfWeek.setDate(currentDate + 1);
				else {
					startOfWeek.setDate(1);
					startOfWeek.setMonth(currentMonth + 1);
				}
			}
			
			// if month has 31 days and still in month
			else if(currentMonth == 0 || currentMonth == 2 || currentMonth == 4 || currentMonth == 6 || currentMonth == 7 || currentMonth == 9 || currentMonth == 11) {
				if(currentDate < 31) {
					startOfWeek.setDate(currentDate + 1);
				}
				else {
					// if not december
					if(currentMonth != 11) {
						startOfWeek.setMonth(currentMonth + 1);
						startOfWeek.setDate(1);
					}
					// if december, jump to janruary
					else {
						startOfWeek.setMonth(0);
						startOfWeek.setDate(1);
					} // end else
				} // end big else
			} // end if month has 31 days else if
			
			 // if month has 30 days and still in month
			else if(currentMonth == 3 || currentMonth == 5 || currentMonth == 8 || currentMonth == 10) {
				if(currentDate < 30) {
					startOfWeek.setDate(currentDate + 1);
				}
				else {
					startOfWeek.setMonth(currentMonth + 1);
					startOfWeek.setDate(1);
				}
			}
		} // end for			
		return eventsForWeek;
	}
	
	@SuppressWarnings("deprecation")
	public ArrayList<Event> getAllEvents(String tblName) throws SQLException {
		
		ArrayList<Event> allEventsArrayList = new ArrayList<Event>();
		
		ResultSet dbOutput = dbStatement.executeQuery("select * from " + tblName);
		
		while(dbOutput.next()) {
			
			if(dbOutput.getInt("isEventRepeated") == 0) {
				eRepeated = false;
			}
			else if(dbOutput.getInt("isEventRepeated") == 1) {
				eRepeated = true;
			}
			
			eID = dbOutput.getInt("eventID");
			eName = dbOutput.getString("eventName");
			eDescription = dbOutput.getString("eventDescription");
			eTotalTime = dbOutput.getInt("eventTotalTime");
			eLocation = dbOutput.getString("eventLocation");
			eStartDay = dbOutput.getInt("eventStartDay");
			eStartMonth = dbOutput.getInt("eventStartMonth");
			eStartYear = dbOutput.getInt("eventStartYear");
			eStartHour = dbOutput.getInt("eventStartHour");
			eStartMin = dbOutput.getInt("eventStartMinutes");
			eEndDay = dbOutput.getInt("eventEndDay");
			eEndMonth = dbOutput.getInt("eventEndMonth");
			eEndYear = dbOutput.getInt("eventEndYear");
			eEndHour = dbOutput.getInt("eventEndHour");
			eEndMin = dbOutput.getInt("eventEndMinutes");
			
			Date startTime = new Date(eStartYear-1900, eStartMonth-1, eStartDay, eStartHour, eStartMin, 0);
			Date stopTime = new Date(eEndYear-1900, eEndMonth-1, eEndDay, eEndHour, eEndMin, 0);
		
					
			Event tempEvent = new Event(eID, eName,eDescription,eLocation,eRepeated,startTime,stopTime);
			allEventsArrayList.add(tempEvent);
		}
		return allEventsArrayList;
	} // end getAllRecords
	
	public void clearAllEvents(String tblName) throws SQLException {
		
		dbStatement.executeUpdate("delete from " + tblName);
	} // end clearAllRecords
	
	public void deleteSingleEventByName(String tblName, Event e) throws SQLException {
		
		String nameToDelete = e.getEventName();
		String delete = "delete from " + tblName + " where eventName='" + nameToDelete + "'";
		
		dbStatement.executeUpdate(delete);		
	} // end deleteEventByName
	
	public void deleteSingleEventByID(String tblName, Event e) throws SQLException {
		
		int idToDelete = e.getEventID();
		String delete = "delete from " + tblName + " where eventID='" + idToDelete + "'";
		
		dbStatement.executeUpdate(delete);
	} // end deleteEventByID
	
	public void deleteSingleEventByTime(String tblName, Event e) throws SQLException {
		
		String startTime = e.startTime.toString();
		String endTime = e.stopTime.toString();
		
		String delete = "delete from " + tblName + "where eventStartTime='" + startTime + "' AND " +
						"eventStopTime='" + endTime + "'";
		
		dbStatement.executeUpdate(delete);
	} // end deleteSingleEventByTime
	
}