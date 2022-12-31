// SRN: PES1UG19CS519
public class Task {
    String taskName;
    String taskType;
    String taskStatus;
    int taskLevel;
    String taskSize;
    String effortRequired;
  
    public Task()
    {
      taskName = "default-task";
      taskType = "default-task-type";
      taskStatus = "default-task-status";
      taskLevel = 1;
      taskSize = "default-task-size";
      effortRequired = "0 day";
    }
  
    public Task(String taskName, String taskType, String taskStatus, int taskLevel, String taskSize, String effortRequired) {
      this.taskName = taskName;
      this.taskType = taskType;
      this.taskStatus = taskStatus;
      this.taskLevel = taskLevel;
      this.taskSize = taskSize;
      this.effortRequired = effortRequired;
    }
  
    public void executedBy(Employee employee) {
      employee.executedBy();
    }
  
    public void openedBy(Employee employee) {
      employee.openedBy();
    }
  }