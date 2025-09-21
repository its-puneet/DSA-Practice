# Write your MySQL query statement below
select email
from Person
group BY 1
having COUNT(*) > 1;