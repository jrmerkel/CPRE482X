$	????@R???Z??q??s?@!-x?W??@$	?5?md???zB?Q???#???-???!?(?*9??"g
=type.googleapis.com/tensorflow.profiler.PerGenericStepDetails&???@@?.?u?;??A??'Hl?@Y
J?ʽ??"g
=type.googleapis.com/tensorflow.profiler.PerGenericStepDetails&???	?@???d????AHlw?}@Ya??+e??"g
=type.googleapis.com/tensorflow.profiler.PerGenericStepDetails&-x?W??@@?3iS5??A??66{@Y??[1Э?"g
=type.googleapis.com/tensorflow.profiler.PerGenericStepDetails&??V??
@^??I?Ը?A?õ?þ	@Y??j,a??"g
=type.googleapis.com/tensorflow.profiler.PerGenericStepDetails&?%?`@??\5ϵ?A???9
@Y;4,F]k??"g
=type.googleapis.com/tensorflow.profiler.PerGenericStepDetails&C??3W@X?%?????ASAEկ4@YgaO;?5??"g
=type.googleapis.com/tensorflow.profiler.PerGenericStepDetails&?ǘ???@?$???}??A??u??@Ywj.7???"g
=type.googleapis.com/tensorflow.profiler.PerGenericStepDetails&q??s?@t?5=((??A??a???@Y?ٲ|]??*	q=
ף?t@2F
Iterator::Model
???#bJ??!      Y@)8??9??1|?a?z?V@:Preprocessing2R
Iterator::Model::FromTensor
??T?????!\??*d#@)??T?????1\??*d#@:Preprocessing:?
]Enqueuing data: you may want to combine small input data chunks into fewer but larger chunks.
?Data preprocessing: you may increase num_parallel_calls in <a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#map" target="_blank">Dataset map()</a> or preprocess the data OFFLINE.
?Reading data from files in advance: you may tune parameters in the following tf.data API (<a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#prefetch" target="_blank">prefetch size</a>, <a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#interleave" target="_blank">interleave cycle_length</a>, <a href="https://www.tensorflow.org/api_docs/python/tf/data/TFRecordDataset#class_tfrecorddataset" target="_blank">reader buffer_size</a>)
?Reading data from files on demand: you should read data IN ADVANCE using the following tf.data API (<a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#prefetch" target="_blank">prefetch</a>, <a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#interleave" target="_blank">interleave</a>, <a href="https://www.tensorflow.org/api_docs/python/tf/data/TFRecordDataset#class_tfrecorddataset" target="_blank">reader buffer</a>)
?Other data reading or processing: you may consider using the <a href="https://www.tensorflow.org/programmers_guide/datasets" target="_blank">tf.data API</a> (if you are not using it now)?
:type.googleapis.com/tensorflow.profiler.BottleneckAnalysis?
both?Your program is POTENTIALLY input-bound because 6.4% of the total step time sampled is spent on 'All Others' time (which could be due to I/O or Python execution or both).no*no9??~{??I?Ϗ?X@Zno>Look at Section 3 for the breakdown of input time on the host.B?
@type.googleapis.com/tensorflow.profiler.GenericStepTimeBreakdown?
$	??.?8??^D*?$??t?5=((??!@?3iS5??	!       "	!       *	!       2$	g{???L
@?iN? ?????a???@!??'Hl?@:	!       B	!       J$		?P????YS? u??ٲ|]??!??[1Э?R	!       Z$		?P????YS? u??ٲ|]??!??[1Э?b	!       JCPU_ONLYY??~{??b q?Ϗ?X@