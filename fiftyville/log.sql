-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports;

-- Find description of murder
SELECT description
FROM crime_scene_reports
WHERE street = 'Humphrey Street'
AND year = 2023
AND month = 7
AND day = 28;
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- Find interview transcripts of 3 ppl
SELECT name, transcript
FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28;

-- Ruth - Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Eugene - I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Raymond - As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Find cars that left the parking lot during that time frame through Ruth's info
SELECT minute, activity, license_plate FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25 AND minute >= 15;

-- POSSIBLE LICENSE PLATES
-- 5P2BI95 94KL13X 6P58WS2 4328GD8 G412CB7 L93JTIZ 322W7JE 0NTHK55

-- Find possible murderers through Eugene's info
SELECT account_number, amount FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- POSSIBLE ACCOUNT NUMBERS AND WITHDRAWAL AMOUNTS
--| 28500762       | 48     |
--| 28296815       | 20     |
--| 76054385       | 60     |
--| 49610011       | 50     |
--| 16153065       | 80     |
--| 25506511       | 20     |
--| 81061156       | 30     |
--| 26013199       | 35     |

-- Find possible callers and reciver numbers through Raymonds info
SELECT caller, receiver FROM phone_calls WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60;

-- POSSIBLE CALLERS AND RECEIVERS
--| (130) 555-0289 | (996) 555-8899 |
--| (499) 555-9472 | (892) 555-8872 |
--| (367) 555-5533 | (375) 555-8161 |
--| (499) 555-9472 | (717) 555-1342 |
--| (286) 555-6063 | (676) 555-6554 |
--| (770) 555-1861 | (725) 555-3243 |
--| (031) 555-6622 | (910) 555-3251 |
--| (826) 555-1652 | (066) 555-9701 |
--| (338) 555-6650 | (704) 555-2131 |


-- Use gathered information to find names fo suspects
SELECT name, passport_number
FROM people
WHERE phone_number IN('(130) 555-0289', '(499) 555-9472', '(367) 555-5533', '(499) 555-9472', '(286) 555-6063', '(770) 555-1861', '(031) 555-6622', '(826) 555-1652', '(338) 555-6650')
AND license_plate IN('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');

-- POSSIBLE NAMES AND PASSPORT NUMBERS
--|  name  | passport_number |
--| Sofia  | 1695452385      |
--| Diana  | 3592750733      |
--| Kelsey | 8294398571      |
--| Bruce  | 5773159633      |

-- Find person through possible account numbers
SELECT people.name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE people.name IN ('Sofia', 'Diana', 'Kelsey', 'Bruce')
AND bank_accounts.account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199);

-- POSSIBLE PEOPLE
-- Bruce and Diana

-- What airports in Fiftyville
SELECT id, abbreviation, full_name FROM airports WHERE city = 'Fiftyville';
-- 8, Fiftyville Regional Airport (CSF)

-- Which flight taken (earliest flight next day)
SELECT destination_airport_id, id FROM flights WHERE origin_airport_id = 8 AND year = 2023 AND month = 7 AND day = 29 ORDER BY hour ASC, minute ASC LIMIT 1;
-- Destination ID is 4 and flight id is 36

-- What destination?
SELECT full_name, city FROM airports WHERE id = 4;
-- LaGuardia Airport, NYC

-- Was Bruce or Diana on this flight
SELECT * FROM passengers WHERE passport_number IN (5773159633, 3592750733) AND flight_id = 36;
-- BRUCE WAS ON THE FLIGHT AND IS THE MURDERER

-- Who is the accomplice
SELECT * FROM people WHERE name = 'Bruce';
-- He called (375) 555-8161
SELECT * FROM people WHERE phone_number = '(375) 555-8161';
-- ROBIN IS THE ACCOMPLICE
