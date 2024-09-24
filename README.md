# Embedded Digital Controllers Project

## Project Overview

This project focuses on the design and implementation of state-feedback controllers for regulating the position and velocity of a DC motor. The project explores a variety of control techniques including **Linear Quadratic Regulator (LQR)**, **Pole Placement**, and various real-world controller implementations using anti-windup and bumpless transfer techniques. The motor used in this project is the **Pololu 37D Metal Gearmotor**, and simulations were carried out in **MATLAB/Simulink**.

## Key Topics and Concepts

### 1. **Motor Description**
   The project utilizes the Pololu 37D DC motor with a quadrature encoder that provides feedback for position and velocity control. This section describes how the motor and encoder work together to enable the control system, including how the encoder signals are processed to calculate motor speed and direction.

### 2. **State Feedback Controllers**
   - **Regulator System**: A full state feedback controller is designed for the motor in its regulator form, where the reference signal is set to zero. This type of controller is based on feedback laws that are designed using either pole placement or LQR methods.
   - **Tracking System**: The state feedback controller is extended to a tracking system with a non-zero reference signal. This requires the addition of integral action to eliminate steady-state errors.

### 3. **Transfer Function Selection**
   The project uses the **tangent method** to derive the transfer function of the motor from its step response. This is done by identifying the inflection point of the response curve and applying a tangent at that point to derive the system’s time constant and dynamic properties.

### 4. **Controller Design**
   - **LQR Design**: The Linear Quadratic Regulator (LQR) method is used to optimize control performance by minimizing a quadratic cost function. The trade-off between system performance and control effort is managed by tuning the weight matrices \( Q_x \) and \( Q_u \).
   - **Pole Placement**: This method is used to assign the closed-loop poles of the system to achieve desired performance characteristics such as settling time and stability.

### 5. **Real Controllers and Issues**
   - **Anti-Windup**: Integrator windup can occur when the control signal exceeds actuator limits, causing the controller to behave as an open-loop system. Anti-windup techniques like **integral subtraction** and **stop summation** are implemented to prevent this.
   - **Bumpless Transfer**: This technique ensures smooth transitions between different control modes (e.g., manual to automatic), preventing system instability and undesired behavior.

### 6. **StateFlow Implementation**
   The project incorporates **StateFlow** to manage transitions between different control strategies (LQR and Pole Placement) in both position and velocity control. The system switches between controllers based on real-time references.

### 7. **Simulations**
   Simulations were conducted in MATLAB/Simulink to evaluate the performance of the designed controllers. Both LQR and Pole Placement methods were tested for velocity and position control. The simulations demonstrated the effectiveness of these controllers in maintaining desired motor performance.

### 8. **Direct Coding**
   After simulations, the project transitions to direct coding of the control logic. This involves manually implementing the control algorithms, including position normalization, error calculation, and control input saturation to prevent excessive actuator demand.

## Results

- **Velocity Control**: Simulations showed that both LQR and Pole Placement techniques produced satisfactory results for velocity control. Settling times were short, and control effort remained low.
- **Position Control**: Position control results were similarly successful, with both methods showing good performance in terms of settling time and steady-state accuracy.
- **Real-World Testing**: The real-world implementations confirmed that the controllers worked well, although slight oscillations were observed due to high gain values. Anti-windup techniques helped reduce these effects in boundary conditions.

## Possible Improvements

The following improvements were identified for future work:
- **Fine-Tuning Gains**: Both the \( K \) and \( K_i \) gains of the LQR and Pole Placement controllers could be adjusted to further reduce oscillations.
- **StateFlow Enhancements**: Incorporating additional logic in StateFlow to allow smooth transitions between speed and position controllers.
- **Improved Anti-Windup**: The anti-windup strategy, particularly the integral subtraction method, could be improved by fine-tuning the \( K_{aw} \) parameter to prevent oscillations near saturation limits.

## Tools Used

- **MATLAB/Simulink**: For system modeling, controller design, and simulation.
- **StateFlow**: For designing control logic and handling multiple controller transitions.
- **Direct C Code**: Implemented to manually control the motor's position and velocity outside of the simulation environment.

## Conclusion

This project demonstrates the application of digital control methods for regulating the speed and position of a DC motor. Both LQR and Pole Placement controllers were successfully designed, simulated, and implemented, with additional real-world considerations like anti-windup and bumpless transfer taken into account.

---

## Contact Information

For any questions, please contact:

- Beniamino Squitieri - bennibeniamino@gmail.com
