# Write your MySQL query statement below

select p.firstName, p.lastName, a.city, a.state
from Person as p, Address as a
where p.personId = a.personId
union
select p.firstName, p.lastName, null, null 
from Person as p
where p.personId not in (select personId from Address);