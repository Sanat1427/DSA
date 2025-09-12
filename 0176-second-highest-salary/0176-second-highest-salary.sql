# Write your MySQL query statement below
Select max(e1.salary) as SecondHighestSalary
from Employee e1
inner join Employee e2
on e1.salary < e2.salary