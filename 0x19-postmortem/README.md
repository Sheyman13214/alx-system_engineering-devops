Incident Postmortem Report: Online Messenger App Outage
Date of Incident: July 30, 2024
 Time of Incident: 12:50 AM - 1:55 AM UTC
 Duration: 1 hour 5 minutes

Summary
On July 30, 2024, from 12:50 AM to 1:55 AM UTC, the online messenger app experienced a service outage, during which users were unable to send or receive messages. The outage affected all users across multiple regions, causing significant disruption. The root cause was identified as a database replication failure that led to an overload on the primary database, preventing the application servers from processing requests.

Impact
User Impact: All users were unable to send or receive messages for the duration of the outage. Approximately 5 million users were affected.
Business Impact: The outage led to a spike in customer support inquiries and a temporary drop in user engagement. Estimated financial impact includes potential loss of revenue from in-app purchases and a decrease in user satisfaction.
Reputation Impact: Social media channels reported widespread user dissatisfaction. The incident led to negative press coverage, highlighting reliability concerns.

Root Cause
The root cause of the outage was a failure in the database replication process. A routine maintenance task inadvertently triggered a failover in the database cluster. The failover process did not complete successfully, leading to a situation where the primary database became overloaded due to unresolved replication lag. This overload caused the application servers to timeout on database requests, leading to the complete inability to process user messages.
Contributing Factors:
Misconfiguration: A misconfiguration in the database cluster’s failover settings allowed a maintenance task to trigger an unintended failover.
Lack of Monitoring: Monitoring tools failed to detect the increasing replication lag early enough to take preventative action.
Delayed Response: The on-call team was delayed in responding to alerts due to notification issues, resulting in a slower resolution of the problem.

Timeline
12:50 AM: Outage begins. Users start reporting issues with sending and receiving messages.
12:55 AM: Monitoring systems detect elevated error rates but fail to correlate with the database issue.
1:00 AM: Customer support receives multiple reports of users unable to access the messaging service.
1:05 AM: Engineering teams are alerted to the issue. Initial investigation points to a potential database problem.
1:15 AM: Engineers identify that the database replication has failed, causing a bottleneck in the primary database.
1:30 AM: Attempts to manually restart the replication process fail. Engineers decide to roll back the failover and revert to the previous stable state.
1:50 AM: The rollback is successful, and database operations return to normal.
1:55 AM: Service is fully restored. Monitoring confirms that error rates have returned to normal levels.

Resolution
To resolve the issue, the engineering team rolled back the database failover to the previous stable configuration. The replication process was restarted manually, and the primary database was stabilized by temporarily diverting traffic to secondary nodes to reduce the load.

Preventative Measures
To prevent similar incidents in the future, the following actions will be taken:
Database Failover Configuration Review:
Review and update the database cluster’s failover settings to prevent unintended failovers during routine maintenance.
Improved Monitoring and Alerts:
Enhance monitoring tools to better detect early signs of replication lag and database load issues.
Implement more granular alerting to ensure faster detection of critical issues.
Incident Response Plan:
Review and update the incident response procedures, including faster escalation protocols and regular drills for the on-call team.
Implement a redundant notification system to ensure that alerts are received by on-call personnel promptly.
Post-Incident Training:
Conduct training sessions for the engineering and operations teams on handling database-related issues and failovers.

Lessons Learned
Redundancy and Resilience: The incident highlighted the need for more robust redundancy in the database infrastructure and better resilience planning for critical components.
Communication: Faster and clearer communication channels between monitoring systems, on-call engineers, and support teams are crucial during an incident.
Proactive Maintenance: Proactive measures should be in place to detect and address potential issues before they escalate into full-blown outages.

Conclusion
The outage on July 30, 2024, served as a critical learning experience for the team. While the impact was significant, the steps outlined above will help ensure that similar issues are avoided in the future, and the overall reliability of the service is improved. The team is committed to delivering a stable and reliable messaging experience to all users.
Prepared by: [Olowomatire oluwaseyifunmi]
 Date: [31th of July , 2024]
 Role: [app manager]
