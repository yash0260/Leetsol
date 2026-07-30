# Write your MySQL query statement below
SELECT name,unique_id FROM Employees as t1 LEFT JOIN EmployeeUNI as t2 ON t1.id =t2.id;