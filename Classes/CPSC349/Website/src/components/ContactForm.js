import { useForm, useController } from 'react-hook-form';
import { zodResolver } from "@hookform/resolvers/zod";
import { string, z } from "zod";
import { register } from 'react-scroll/modules/mixins/scroller';
import { useState } from "react";
import './ContactForm.css';


const schema = z.object({
    name: string().min(1, { message: "Name is required" }),
    email: string().email(),
    message: string(),
});

const ContactForm = ({ onSave, user = {} }) => {
    const { register, control, handleSubmit, reset, formState } = useForm({
        defaultValues: user,
        resolver: zodResolver(schema),
    });

    const { errors } = formState;
    const [showSuccess, setShowSuccess] = useState(false);

    const handleSave = (formValues) => {
        onSave(formValues);
        reset();
        setShowSuccess(true);
    };


    return (
        <div>
            {!showSuccess ? (
                <form onSubmit={handleSubmit(handleSave)}>
                    <div>
                        <p>
                            Name <mark>*</mark>
                        </p>
                        <input {...register('name')} />
                        <div style={{ color: 'red' }}>{errors.name?.message}</div>
                    </div>

                    <div>
                        <p>
                            Email <mark>*</mark>
                        </p>
                        <input {...register('email')} />
                        <div style={{ color: 'red' }}>{errors.email?.message}</div>
                    </div>

                    <div>
                        <p>Message</p>
                        <textarea {...register('message')} className="message-box" />
                    </div>

                    <div style={{ marginTop: '12px' }}>
                        <button className="submit-button" type="submit">
                            Submit
                        </button>
                    </div>
                </form>
            ) : (
                <div className="success-message">
                    <p>Your message was sent successfully!</p>
                </div>
            )}
        </div>
    );
};

export default ContactForm;