-- MySQL dump 10.13  Distrib 5.7.21, for Linux (x86_64)
--
-- Host: localhost    Database: P_S_FA_Interaction
-- ------------------------------------------------------
-- Server version	5.7.21-1ubuntu1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `ADMIN`
--

/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ADMIN` (
  `A_Id` varchar(10) NOT NULL,
  `A_Password` varchar(15) NOT NULL,
  `A_EmailId` varchar(22) NOT NULL,
  PRIMARY KEY (`A_Id`),
  UNIQUE KEY `A_EmailId` (`A_EmailId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ADMIN`
--

LOCK TABLES `ADMIN` WRITE;
/*!40000 ALTER TABLE `ADMIN` DISABLE KEYS */;
INSERT INTO `ADMIN` VALUES ('dinesh','dinesh123','dinesh1@gmail.com');
/*!40000 ALTER TABLE `ADMIN` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `F_ADVISOR1`
--

DROP TABLE IF EXISTS `F_ADVISOR1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `F_ADVISOR1` (
  `FA_Id` varchar(10) NOT NULL,
  `FA_Fname` varchar(20) DEFAULT NULL,
  `FA_Lname` varchar(20) DEFAULT NULL,
  `FA_EmailId` varchar(30) NOT NULL,
  `FA_MobileNo` char(10) DEFAULT NULL,
  `FA_Password` varchar(15) NOT NULL,
  PRIMARY KEY (`FA_Id`),
  UNIQUE KEY `FA_EmailId` (`FA_EmailId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `F_ADVISOR1`
--

LOCK TABLES `F_ADVISOR1` WRITE;
/*!40000 ALTER TABLE `F_ADVISOR1` DISABLE KEYS */;
INSERT INTO `F_ADVISOR1` VALUES ('CDS01','Sadagopan','Narasimhan','sady@iiitdm.ac.in','9874563214','s@DDY'),('COM01','BALA SUBRAMANYYAM','SIVALSELVEN','sivaselvanb@iiitdm.ac.in','7654321890','sivaselvanb'),('EDM01','K','Selva Jyoti','kselvajyoti@gmail.com','8671549672','ksj@789'),('MDM01','Srinivan','Pandian','srpandian@gmail.com','8125463254','srpan##');
/*!40000 ALTER TABLE `F_ADVISOR1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `F_ADVISOR2`
--

DROP TABLE IF EXISTS `F_ADVISOR2`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `F_ADVISOR2` (
  `FA_Id` varchar(10) NOT NULL,
  `FA_Degree` varchar(11) NOT NULL,
  `FA_Branch` varchar(10) NOT NULL,
  `FA_Batch` int(11) NOT NULL,
  PRIMARY KEY (`FA_Degree`,`FA_Branch`,`FA_Batch`),
  KEY `FA_Id` (`FA_Id`),
  CONSTRAINT `F_ADVISOR2_ibfk_1` FOREIGN KEY (`FA_Id`) REFERENCES `F_ADVISOR1` (`FA_Id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `F_ADVISOR2`
--

LOCK TABLES `F_ADVISOR2` WRITE;
/*!40000 ALTER TABLE `F_ADVISOR2` DISABLE KEYS */;
INSERT INTO `F_ADVISOR2` VALUES ('CDS01','MDES','CDS',2017),('COM01','BTech','COE',2016),('COM01','DD','MFD',2015),('EDM01','BTech','EDM',2016),('MDM01','BTech','MDM',2017);
/*!40000 ALTER TABLE `F_ADVISOR2` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PARENT`
--

DROP TABLE IF EXISTS `PARENT`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PARENT` (
  `RNo` char(9) NOT NULL,
  `F_Fname` varchar(20) DEFAULT NULL,
  `F_Lname` varchar(20) DEFAULT NULL,
  `M_Fname` varchar(20) DEFAULT NULL,
  `M_Lname` varchar(20) DEFAULT NULL,
  `P_EmailId` varchar(40) DEFAULT NULL,
  `P_MobileNo1` char(10) DEFAULT NULL,
  `P_MobileNo2` char(10) DEFAULT NULL,
  `G_Fname` varchar(20) DEFAULT NULL,
  `G_Lname` varchar(20) DEFAULT NULL,
  `G_MobileNo` char(10) DEFAULT NULL,
  `P_Password` varchar(15) NOT NULL,
  PRIMARY KEY (`RNo`),
  CONSTRAINT `PARENT_ibfk_1` FOREIGN KEY (`RNo`) REFERENCES `S_COLLEGE` (`RNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PARENT`
--

LOCK TABLES `PARENT` WRITE;
/*!40000 ALTER TABLE `PARENT` DISABLE KEYS */;
INSERT INTO `PARENT` VALUES ('CDS17M001','Bharath','Ravi','Bharath','Sri Malli','bharath@gmail.com','7598453289','9874562548','Kona','Harshita','7598425668','@!123'),('COE16B041','GORANTLA','SREE KRISHNA PRASAD','GORANTLA','ANITA','gskprasad@gmail.com','9440471610','9293600614','GORANTLA','JASWANTH RAYUDU','8985848899','Maggi$833'),('COE16B042','Subramanian','Maheswaran','Subramanian','Divya','sm@gmail.com','8649757592','756984254','Null','Null','Null','subbu'),('COE16B043','Telluri','Gangadhara Reddy','Kanchumarthy','Sri Devi','gtelluri@gmail.com','9849399738','9848458317','NUll','Null','Null','g@nga'),('EDM16B008','Gatram','Mallikarjuna','Gatram','Radha','mallikarjuna@gmail.com','8574369875','7598534685','Pratipati','Ravi Sekhar','8549631245','g@tram!'),('EDM16B035','Takkelapati','Srinivasan','Takkelapati','Madhavi Latha','tsr10@gmail.com','8964257816','9657425367','Null','Null','Null','tsr10'),('EDM16B038','Yadavalli','Babu','Yadavalli','Sudha','yadavallibabu@gmail.com','8642513497','7598423648','Charles','Gowrav','8469521349','b@bu'),('EVD16I010','Mamidi','Venkatarao','Mamidi','Sowjanya','mvenkatarao@gmail.com','759842654','8964512357','Talluri','Venkatesh','7598426586','venky'),('EVD16I018','Gondayala','JayRam','Gondayala','Gayathri','gondayala@gmail.com','7123456895','9456871235','Gali','Tanmai','7598426541','Gond@'),('MDM17B016','Dondapati','Shasank','Dondapati','Neha','dondapatis@gmail.com','9845684217','7598123654','Kurra','Harshita','9847895897','dond@'),('MFD15I033','Tatavarthy','Srinivasrao','Tatavarthy','Lalitha','tata@gmail.com','7598426576','8698425613','Sharma','Vineesh','8456987455','&%$');
/*!40000 ALTER TABLE `PARENT` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `S_ATTENDANCE`
--

DROP TABLE IF EXISTS `S_ATTENDANCE`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `S_ATTENDANCE` (
  `RNo` char(9) NOT NULL,
  `Month` int(11) NOT NULL,
  `Performance` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`RNo`,`Month`),
  CONSTRAINT `S_ATTENDANCE_ibfk_1` FOREIGN KEY (`RNo`) REFERENCES `S_COLLEGE` (`RNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `S_ATTENDANCE`
--

LOCK TABLES `S_ATTENDANCE` WRITE;
/*!40000 ALTER TABLE `S_ATTENDANCE` DISABLE KEYS */;
INSERT INTO `S_ATTENDANCE` VALUES ('CDS17M001',1,'Good'),('CDS17M001',2,'Good'),('CDS17M001',3,'Good'),('CDS17M001',4,'Good'),('COE16B041',1,'Good'),('COE16B041',2,'Average'),('COE16B041',3,'Poor'),('COE16B041',4,'Good'),('COE16B042',1,'Good'),('COE16B042',2,'Average'),('COE16B042',3,'Average'),('COE16B042',4,'Good'),('COE16B043',1,'Good'),('COE16B043',2,'Average'),('COE16B043',3,'Good'),('COE16B043',4,'Good'),('EDM16B008',1,'Good'),('EDM16B008',2,'Good'),('EDM16B008',3,'Good'),('EDM16B008',4,'Good'),('EDM16B035',1,'Good'),('EDM16B035',2,'Average'),('EDM16B035',3,'Good'),('EDM16B035',4,'Good'),('EDM16B038',1,'Good'),('EDM16B038',2,'Poor'),('EDM16B038',3,'Good'),('EDM16B038',4,'Good'),('EVD16I010',1,'Good'),('EVD16I010',2,'Average'),('EVD16I010',3,'Poor'),('EVD16I010',4,'Poor'),('EVD16I018',1,'Poor'),('EVD16I018',2,'Good'),('EVD16I018',3,'Average'),('EVD16I018',4,'Poor'),('MDM17B016',1,'Good'),('MDM17B016',2,'Good'),('MDM17B016',3,'Good'),('MDM17B016',4,'Good'),('MFD15I033',1,'Good'),('MFD15I033',2,'Poor'),('MFD15I033',3,'Poor'),('MFD15I033',4,'Poor');
/*!40000 ALTER TABLE `S_ATTENDANCE` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `S_CGPA`
--

DROP TABLE IF EXISTS `S_CGPA`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `S_CGPA` (
  `RNo` char(9) NOT NULL,
  `Cgpa` decimal(3,2) DEFAULT NULL,
  PRIMARY KEY (`RNo`),
  CONSTRAINT `S_CGPA_ibfk_1` FOREIGN KEY (`RNo`) REFERENCES `S_COLLEGE` (`RNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `S_CGPA`
--

LOCK TABLES `S_CGPA` WRITE;
/*!40000 ALTER TABLE `S_CGPA` DISABLE KEYS */;
INSERT INTO `S_CGPA` VALUES ('CDS17M001',8.82),('COE16B041',9.02),('COE16B042',8.98),('COE16B043',8.85),('EDM16B008',8.82),('EDM16B035',8.85),('EDM16B038',8.01),('EVD16I010',8.89),('EVD16I018',8.90),('MDM17B016',9.60),('MFD15I033',8.90);
/*!40000 ALTER TABLE `S_CGPA` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `S_COLLEGE`
--

DROP TABLE IF EXISTS `S_COLLEGE`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `S_COLLEGE` (
  `RNo` char(9) NOT NULL,
  `EmailId` char(22) NOT NULL,
  `Degree` varchar(11) NOT NULL,
  `Branch` varchar(10) NOT NULL,
  `SemNo` int(11) DEFAULT NULL,
  `FA_Id` varchar(10) DEFAULT NULL,
  `Hostel_Name` varchar(20) DEFAULT NULL,
  `Hostel_RoomNo` int(11) DEFAULT NULL,
  PRIMARY KEY (`RNo`),
  UNIQUE KEY `EmailId` (`EmailId`),
  KEY `FA_Id` (`FA_Id`),
  KEY `Hostel_Name` (`Hostel_Name`),
  CONSTRAINT `S_COLLEGE_ibfk_1` FOREIGN KEY (`FA_Id`) REFERENCES `F_ADVISOR1` (`FA_Id`),
  CONSTRAINT `S_COLLEGE_ibfk_2` FOREIGN KEY (`Hostel_Name`) REFERENCES `S_HOSTEL` (`Hostel_Name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `S_COLLEGE`
--

LOCK TABLES `S_COLLEGE` WRITE;
/*!40000 ALTER TABLE `S_COLLEGE` DISABLE KEYS */;
INSERT INTO `S_COLLEGE` VALUES ('CDS17M001','cds17m001@iiitdm.ac.in','MDES','CDS',2,'CDS01','Ashoka Boys Hostel',415),('COE16B041','coe16b041@iiitdm.ac.in','BTech','COE',4,'COM01','Aswatha Girls Hostel',910),('COE16B042','coe16b042@gmail.com','BTech','COE',4,'COM01','Aswatha Girls Hostel',906),('COE16B043','coe16b043@iiitdm.ac.in','BTech','COE',4,'COM01','Aswatha Girls Hostel',905),('EDM16B008','edm16b008@iiitdm.ac.in','BTech','EDM',4,'EDM01','Ashoka Boys Hostel',1405),('EDM16B035','edm16b035@gmail.com','BTech','EDM',4,'EDM01','Aswatha Girls Hostel',909),('EDM16B038','edm16b010@gmail.com','BTech','EDM',4,'EDM01','Aswatha Boys Hostel',1308),('EVD16I010','evd16i010@iiitdm.ac.in','DD','EVD',4,'EDM01','Aswatha Girls Hostel',1005),('EVD16I018','evd16i018@iiitdm.ac.in','DD','EVD',4,'EDM01','Ashoka Boys Hostel',201),('MDM17B016','mdm16b016@iiitdm.ac.in','BTech','MDM',2,'MDM01','Aswatha Boys Hostel',512),('MFD15I033','mfd15i033@iiitdm.ac.in','DD','MFD',6,'COM01','Ashoka Boys Hostel',100);
/*!40000 ALTER TABLE `S_COLLEGE` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `S_GPA`
--

DROP TABLE IF EXISTS `S_GPA`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `S_GPA` (
  `RNo` char(9) NOT NULL,
  `SemNo` int(11) NOT NULL,
  `GPA` decimal(3,2) DEFAULT NULL,
  PRIMARY KEY (`RNo`,`SemNo`),
  CONSTRAINT `S_GPA_ibfk_1` FOREIGN KEY (`RNo`) REFERENCES `S_COLLEGE` (`RNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `S_GPA`
--

LOCK TABLES `S_GPA` WRITE;
/*!40000 ALTER TABLE `S_GPA` DISABLE KEYS */;
INSERT INTO `S_GPA` VALUES ('CDS17M001',1,8.82),('COE16B041',1,8.83),('COE16B041',2,9.23),('COE16B041',3,9.09),('COE16B042',1,8.78),('COE16B042',2,9.03),('COE16B042',3,8.92),('COE16B043',1,8.61),('COE16B043',2,8.82),('COE16B043',3,8.85),('EDM16B008',1,8.82),('EDM16B008',2,8.85),('EDM16B008',3,7.85),('EDM16B035',1,8.34),('EDM16B035',2,8.68),('EDM16B035',3,8.48),('EDM16B038',1,8.23),('EDM16B038',2,7.90),('EDM16B038',3,8.85),('EVD16I010',1,8.49),('EVD16I010',2,8.64),('EVD16I010',3,8.85),('EVD16I018',1,8.78),('EVD16I018',2,7.90),('EVD16I018',3,9.50),('MDM17B016',1,9.60),('MFD15I033',1,8.20),('MFD15I033',2,8.47),('MFD15I033',3,9.07),('MFD15I033',4,8.54),('MFD15I033',5,8.84);
/*!40000 ALTER TABLE `S_GPA` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `S_GRADE`
--

DROP TABLE IF EXISTS `S_GRADE`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `S_GRADE` (
  `RNo` char(9) NOT NULL,
  `Course_No` varchar(20) NOT NULL,
  `SemNo` int(11) DEFAULT NULL,
  `Grade` char(1) DEFAULT NULL,
  PRIMARY KEY (`RNo`,`Course_No`),
  CONSTRAINT `S_GRADE_ibfk_1` FOREIGN KEY (`RNo`) REFERENCES `S_COLLEGE` (`RNo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `S_GRADE`
--

LOCK TABLES `S_GRADE` WRITE;
/*!40000 ALTER TABLE `S_GRADE` DISABLE KEYS */;
INSERT INTO `S_GRADE` VALUES ('CDS17M001','DES323T',1,'A'),('CDS17M001','MAT333T',1,'S'),('COE16B041','COM105P',1,'S'),('COE16B041','COM105T',1,'S'),('COE16B041','COM206T',3,'S'),('COE16B041','ELE103T',2,'S'),('COE16B041','MAT204T',3,'B'),('COE16B041','PHY107P',2,'A'),('COE16B042','COM205T',3,'A'),('COE16B042','DES104P',2,'B'),('COE16B042','DES201T',3,'S'),('COE16B042','ELE103T',2,'A'),('COE16B042','MAT104T',1,'B'),('COE16B043','COM105T',1,'A'),('COE16B043','COM206P',3,'S'),('COE16B043','COM209P',3,'A'),('COE16B043','DES102T',2,'A'),('COE16B043','ELE103T',2,'S'),('COE16B043','INT110P',1,'A'),('COE16B043','PHY108T',1,'S'),('EDM16B008','ELE223P',2,'A'),('EDM16B008','ELE223T',3,'S'),('EDM16B008','INT108T',1,'A'),('EDM16B008','INT109P',1,'S'),('EDM16B008','INT111P',2,'A'),('EDM16B008','MAN102T',2,'S'),('EDM16B035','DES105P',2,'S'),('EDM16B035','ELE217T',3,'S'),('EDM16B035','ELE218T',3,'A'),('EDM16B035','INT107T',1,'A'),('EDM16B035','MAT105P',2,'A'),('EDM16B035','PHY107T',1,'S'),('EDM16B038','DES103T',1,'A'),('EDM16B038','DES210T',3,'A'),('EDM16B038','INT111P',2,'A'),('EDM16B038','MAT104T',1,'B'),('EDM16B038','MAT204T',3,'S'),('EDM16B038','PHY107T',2,'B'),('EVD16I010','COM105T',1,'A'),('EVD16I010','DES102T',2,'S'),('EVD16I010','DES103T',1,'S'),('EVD16I010','MAN201T',3,'C'),('EVD16I010','MAT105T',2,'C'),('EVD16I010','MAT204T',3,'A'),('EVD16I018','COM105T',1,'S'),('EVD16I018','ELE223P',3,'S'),('EVD16I018','INT108T',1,'B'),('EVD16I018','MAT204T',3,'S'),('EVD16I018','PHY107P',2,'S'),('EVD16I018','PHY107T',2,'A'),('MDM17B016','DES111P',2,'B'),('MDM17B016','DES121P',3,'S'),('MDM17B016','MEC102T',1,'S'),('MDM17B016','MEC121',3,'S'),('MDM17B016','MEC2233P',2,'S'),('MDM17B016','PHY107T',1,'A'),('MFD15I033','COM105T',2,'S'),('MFD15I033','COM444P',5,'B'),('MFD15I033','DES103T',1,'S'),('MFD15I033','DES120P',3,'S'),('MFD15I033','DES229P',3,'A'),('MFD15I033','ELE103T',1,'S'),('MFD15I033','ELT102P',4,'A'),('MFD15I033','ELT102T',4,'S'),('MFD15I033','MAN102T',2,'C'),('MFD15I033','MAT444P',5,'A'),('MFD15I033','MEC103T',3,'B');
/*!40000 ALTER TABLE `S_GRADE` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `S_HOSTEL`
--

DROP TABLE IF EXISTS `S_HOSTEL`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `S_HOSTEL` (
  `Hostel_Name` varchar(20) NOT NULL,
  `Hostel_WardenName` varchar(20) NOT NULL,
  `Hostel_LandlineNo` varchar(10) DEFAULT NULL,
  `Warden_PhoneNo` char(10) DEFAULT NULL,
  PRIMARY KEY (`Hostel_Name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `S_HOSTEL`
--

LOCK TABLES `S_HOSTEL` WRITE;
/*!40000 ALTER TABLE `S_HOSTEL` DISABLE KEYS */;
INSERT INTO `S_HOSTEL` VALUES ('Ashoka Boys Hostel','Noor Mohammad','0442346572','7812345689'),('Aswatha Boys Hostel','Noor Mohammad','0442345672','7812345689'),('Aswatha Girls Hostel','Binsu','442567819','7654321983');
/*!40000 ALTER TABLE `S_HOSTEL` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `S_PERSONAL1`
--

DROP TABLE IF EXISTS `S_PERSONAL1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `S_PERSONAL1` (
  `First_Name` varchar(15) NOT NULL,
  `Last_Name` varchar(15) NOT NULL,
  `Gender` char(1) NOT NULL,
  PRIMARY KEY (`First_Name`,`Last_Name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `S_PERSONAL1`
--

LOCK TABLES `S_PERSONAL1` WRITE;
/*!40000 ALTER TABLE `S_PERSONAL1` DISABLE KEYS */;
INSERT INTO `S_PERSONAL1` VALUES ('Bharath','Chandra','M'),('Dondapati','MohanVamsi','M'),('Gatram','Manoj','M'),('Gondayala','Phani','M'),('Gorantla','Meghana','F'),('Gunturu','Sowmya','F'),('Maheswaran','Vineetha','F'),('Mamidi','Snigdha','F'),('Takkelapati','Harika','F'),('Tatavarthy','Prasanna','F'),('Telluri','Meghana Reddy','F'),('Yadavalli','Avinash','M');
/*!40000 ALTER TABLE `S_PERSONAL1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `S_PERSONAL2`
--

DROP TABLE IF EXISTS `S_PERSONAL2`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `S_PERSONAL2` (
  `RNo` char(9) NOT NULL,
  `First_Name` varchar(15) NOT NULL,
  `Last_Name` varchar(15) NOT NULL,
  `DOB` date DEFAULT NULL,
  `Mobile_No` char(10) DEFAULT NULL,
  `Blood_Group` varchar(3) DEFAULT NULL,
  `Address` varchar(30) NOT NULL,
  `Password` varchar(15) NOT NULL,
  PRIMARY KEY (`RNo`),
  UNIQUE KEY `Mobile_No` (`Mobile_No`),
  KEY `First_Name` (`First_Name`),
  CONSTRAINT `S_PERSONAL2_ibfk_1` FOREIGN KEY (`First_Name`) REFERENCES `S_PERSONAL1` (`First_Name`),
  CONSTRAINT `S_PERSONAL2_ibfk_2` FOREIGN KEY (`RNo`) REFERENCES `S_COLLEGE` (`RNo`),
  CONSTRAINT `S_PERSONAL2_ibfk_3` FOREIGN KEY (`First_Name`) REFERENCES `S_PERSONAL1` (`First_Name`),
  CONSTRAINT `S_PERSONAL2_ibfk_4` FOREIGN KEY (`First_Name`) REFERENCES `S_PERSONAL1` (`First_Name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `S_PERSONAL2`
--

LOCK TABLES `S_PERSONAL2` WRITE;
/*!40000 ALTER TABLE `S_PERSONAL2` DISABLE KEYS */;
INSERT INTO `S_PERSONAL2` VALUES ('CDS17M001','Bharath','Chandra','1996-03-02','7598426786','B+','Warangal,AP','Bharath'),('COE16B041','Gorantla','Meghana','1999-06-18','8332886789','O+','Chiral, A.P.','Maggi833'),('COE16B042','Maheswaran','Vinitha','1999-07-24','9487117578','O+','Adyar,TN','Vini_123'),('COE16B043','Telluri','Meghana Reddy','1999-02-08','9618402321','O+','Guntur,A.P.','Dolly123'),('EDM16B008','Gatram','Manoj','1999-08-16','8746953241','B+','Chilaluripeta,AP','Man@j'),('EDM16B038','Yadavalli','Avinash','1999-01-24','8642541357','A-','Rajmundry,A.P','@vinah'),('EVD16I010','Mamidi','Snigdha','1999-04-23','7598423651','B+','Vizag,A.P.','sniggy'),('EVD16I018','Gondayala','Phani','1998-02-18','7598426541','A-','Bhimavaram,AP','Phan!'),('MDM17B016','Dondapati','MohanVamsi','2000-03-20','9547895785','O+','Hyderabad,AP','vamsi2000'),('MFD15I033','Tatavarthy','Prasanna','1997-09-23','7598426575','A-','Vijayawada,AP','T@t@');
/*!40000 ALTER TABLE `S_PERSONAL2` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-05-08  0:51:53
