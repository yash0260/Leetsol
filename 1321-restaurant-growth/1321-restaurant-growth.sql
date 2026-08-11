# Write your MySQL query statement below
WITH daily AS (
    SELECT
        visited_on,
        SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),

windowed AS (
    SELECT
        visited_on,
        amount,
        SUM(amount) OVER (
            ORDER BY visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS seven_day_total,
        ROW_NUMBER() OVER (
            ORDER BY visited_on
        ) AS rn
    FROM daily
)

SELECT
    visited_on,
    seven_day_total AS amount,
    ROUND(seven_day_total / 7, 2) AS average_amount
FROM windowed
WHERE rn >= 7
ORDER BY visited_on;