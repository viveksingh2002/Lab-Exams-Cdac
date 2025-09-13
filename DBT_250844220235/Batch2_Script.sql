Create database LabExam;

use LabExam;

CREATE TABLE `passengers` (
  `PassengerID` int NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Age` int DEFAULT NULL,
  `City` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`PassengerID`)
) ;


INSERT INTO `passengers` VALUES (1,'Ravi Kumar',30,'Delhi'),(2,'Ananya Verma',15,'Mumbai'),(3,'Neha Gupta',28,'Kolkata'),(4,'Shanti Devi',65,'Delhi'),(5,'Priya Singh',22,'Delhi');

CREATE TABLE `trains` (
  `TrainID` int NOT NULL,
  `TrainName` varchar(50) DEFAULT NULL,
  `Source` varchar(50) DEFAULT NULL,
  `Destination` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`TrainID`)
) ;

INSERT INTO `trains` VALUES (101,'Rajdhani Express','Delhi','Mumbai'),(102,'Shatabdi Express','Delhi','Kolkata'),(103,'Chennai Express','Chennai','Delhi'),(104,'Duronto Express','Kolkata','Mumbai'),(105,'Deccan Queen','Mumbai','Pune');


CREATE TABLE `bookings` (
  `BookingID` int NOT NULL,
  `PassengerID` int DEFAULT NULL,
  `TrainID` int DEFAULT NULL,
  `BookingDate` date DEFAULT NULL,
  `SeatNo` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`BookingID`),
  KEY `PassengerID` (`PassengerID`),
  KEY `TrainID` (`TrainID`),
  CONSTRAINT `bookings_ibfk_1` FOREIGN KEY (`PassengerID`) REFERENCES `passengers` (`PassengerID`),
  CONSTRAINT `bookings_ibfk_2` FOREIGN KEY (`TrainID`) REFERENCES `trains` (`TrainID`)
);

INSERT INTO `bookings` VALUES (1001,1,101,'2023-09-01','A1-21'),(1002,2,101,'2023-09-01','A1-22'),(1003,3,102,'2023-09-02','B2-15'),(1004,4,103,'2023-09-03','C1-10'),(1005,5,104,'2023-09-04','D1-5'),(1006,1,105,'2023-09-05','E1-2'),(1007,2,104,'2023-09-06','D2-12'),(1008,3,103,'2023-09-07','C2-7');

