# Write your MySQL query statement below
SELECT r.contest_id , ROUND(count(r.user_id)*100/(SELECT COUNT(*) FROM Users),2) as percentage
FROM Register r
Group by r.contest_id order by percentage desc , r.contest_id asc;