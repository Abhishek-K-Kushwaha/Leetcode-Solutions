# Write your MySQL query statement below

select d.name as Department, e.name as Employee, e.salary as Salary 
from Department as d, Employee as e
where d.id = e.departmentId and (d.id, e.salary) in
(select departmentId, max(salary) from employee 
group by departmentId);

