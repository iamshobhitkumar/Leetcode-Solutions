# Write your MySQL query statement below/
select firstName, lastName, city, state from Person LEFT JOIN Address ON Person.personId = Address.personId;